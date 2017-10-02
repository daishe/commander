# Commander - the variation of the command design pattern

## Example
All example files can be compiled and executed on their own (you only need commander headers).

### rectangle_painter
Let's take a first simplest example the rectangle_painter command. As the name suggests - it will print to stdout rectangle.

The class (and its usage) could look like this:
```cpp
#include <iostream>
#include <utility>

template <typename Length>
class rectangle_painter
{
    public:
        using length_type = Length;

        void operator ()() const
        {
            for (length_type y = 0; y < this->length_.second; ++y) {
                for (length_type x = 0; x < this->length_.first; ++x)
                    std::cout << this->fill_;
                std::cout << '\n';
            }
        };

        void fill(char f)
        { this->fill_ = f; };

        void x(const length_type& xl)
        { this->length_.first = xl; };

        void y(const length_type& yl)
        { this->length_.second = yl; };

    private:
        std::pair<length_type, length_type> length_ = std::pair<length_type, length_type>(0, 0);
        char fill_ = char(' ');
};

int main(int /*argc*/, const char ** /*argv*/)
{
    rectangle_painter<int> rp;
    rp.x(8);
    rp.y(3);
    rp.fill('x');
    rp();
}
```
Everything is ok. It isn't general interface, but it works.

Let's assume that later we extend the architecture of our application. We introduce other classes (for example circle and square) and value checks to all set functions. So we need to create some exception type (of course we can return boolean value with would indicate failure, but then it would be the caller problem). Also using all classes is a problem (each has a different interface) even in template code.  The usage quickly gets kind of clumsy. It is especially painful if those are some important and large pieces in an application.

### rectangle_painter with console-like interface
Commander approach is to enable the ability to embed console-like interface.
```cpp
#include <array>
#include <iostream>
#include <string>
#include <string_view>
#include <utility>

#include <boost/lexical_cast.hpp>
#include <commander.hpp>

template <typename Length>
class rectangle_painter
{
    public:
        using length_type = Length;

        template <typename... Types>
        void operator ()(Types&&... values)
        {
            if constexpr (sizeof...(values) != 0)
                ((*this) << values << ...);

            this->parser_();
            for (length_type y = 0; y < this->length_.second; ++y) {
                for (length_type x = 0; x < this->length_.first; ++x)
                    std::cout << this->fill_;
                std::cout << '\n';
            }
        }

        template <typename T>
        rectangle_painter<length_type>& operator <<(T&& value)
        {
            if constexpr (commander::func::is_exec_v(value)) {
                value(*this);
            }
            else {
                auto tup = std::make_tuple(
                    commander::make_empty_storage(
                        commander::no_value,
                        [](const std::string_view& header) { return commander::compare_disjunction(header, "-x", "-w", "--width"); },
                        commander::make_applier(
                            [this](const length_type& xl) { this->length_.first = xl; return true; },
                            [this](const std::string_view& xl) { this->length_.first = boost::lexical_cast<length_type>(xl); return true; }
                        )
                    ),
                    commander::make_empty_storage(
                        commander::no_value,
                        [](const std::string_view& header) { return commander::compare_disjunction(header, "-y", "-h", "--height"); },
                        commander::make_applier(
                            [this](const length_type& yl) { this->length_.second = yl; return true; },
                            [this](const std::string_view& yl) { this->length_.second = boost::lexical_cast<length_type>(yl); return true; }
                        )
                    ),
                    commander::make_empty_storage(
                        commander::no_value,
                        [](const std::string_view& header) { return commander::compare_disjunction(header, "-f", "--fill"); },
                        commander::make_applier(
                            [this](const char& f) { this->fill_ = f; return true; },
                            [this](const std::string_view& f) { this->fill_ = boost::lexical_cast<char>(f); return true; }
                        )
                    )
                );

                this->parser_(std::forward<T>(value), [&](const auto& arg, const auto& head, auto&& value) {
                    return commander::tuple_visit_disjunction([&](const auto& storage) {
                        if (storage.match(arg, head))
                            return storage.apply(value);
                        return false;
                    }, tup);
                });
            }
            return *this;
        }

    private:
        commander::basic_parser<std::string_view, std::string> parser_;
        std::pair<length_type, length_type> length_ = std::pair<length_type, length_type>(0, 0);
        char fill_ = char(' ');
};

int main(int /*argc*/, const char ** /*argv*/)
{
    try {
        rectangle_painter<int> rp;

        // Let's set x to 12, y to 3 and use 'o' as filling character.
        rp << "-x" << "12" << "-y=3" << "--fill=o";

        // No, no, no - let's change x to 8, use 'x' as filling character and then execute.
        rp << "--width" << 8 << "-f" << 'x' << commander::exec<>();
    }
    catch(...) {
        std::cout << "Whooops..." << '\n';
        return 1;
    }
}
```

### rectangle_painter expanded
Let's expand our example and introduce a new option - invert.
```cpp
#include <array>
#include <iostream>
#include <string>
#include <string_view>
#include <utility>

#include <boost/lexical_cast.hpp>
#include <commander.hpp>

template <typename Length>
class rectangle_painter
{
    public:
        using length_type = Length;

        template <typename... Types>
        void operator ()(Types&&... values)
        {
            if constexpr (sizeof...(values) != 0)
                ((*this) << values << ...);

            this->parser_();
            for (length_type y = 0; y < this->length_.second; ++y) {
                for (length_type x = 0; x < this->length_.first; ++x)
                    std::cout << this->fill_;
                std::cout << '\n';
            }
            std::cout << std::flush;
        }

        template <typename T>
        rectangle_painter<length_type>& operator <<(T&& value)
        {
            if constexpr (commander::func::is_exec_v(value)) {
                value(*this);
            }
            else {
                auto tup = std::make_tuple(
                    commander::make_empty_storage(
                        commander::no_value,
                        [](const std::string_view& header) { return commander::compare_disjunction(header, "-x", "-w", "--width"); },
                        commander::make_applier(
                            [this](const width_option<length_type>& xl) { this->length_.first = xl.length; return true; },
                            [this](const length_type& xl) { this->length_.first = xl; return true; },
                            [this](const std::string_view& xl) { this->length_.first = boost::lexical_cast<length_type>(xl); return true; }
                        )
                    ),
                    commander::make_empty_storage(
                        commander::no_value,
                        [](const std::string_view& header) { return commander::compare_disjunction(header, "-y", "-h", "--height"); },
                        commander::make_applier(
                            [this](const height_option<length_type>& yl) { this->length_.second = yl.length; return true; },
                            [this](const length_type& yl) { this->length_.second = yl; return true; },
                            [this](const std::string_view& yl) { this->length_.second = boost::lexical_cast<length_type>(yl); return true; }
                        )
                    ),
                    commander::make_empty_storage(
                        commander::no_value,
                        [](const std::string_view& header) { return commander::compare_disjunction(header, "-f", "--fill"); },
                        commander::make_applier(
                            [this](const fill_option& f) { this->fill_ = f.character; return true; },
                            [this](const char& f) { this->fill_ = f; return true; },
                            [this](const std::string_view& f) { this->fill_ = boost::lexical_cast<char>(f); return true; }
                        )
                    ),
                    commander::make_empty_storage(
                        commander::no_value,
                        [](const std::string_view& header) { return commander::compare_disjunction(header, "-i", "--inv", "--invert"); },
                        commander::make_applier(
                            [this](const invert_option&) { std::swap(this->length_.first, this->length_.second); return true; },
                            commander::make_type_applier<commander::type_list<commander::no_value_t, commander::placeholder_t>>(
                                [this]() { std::swap(this->length_.first, this->length_.second); return true; }
                            ),
                            [this](const bool& i) { if (i) std::swap(this->length_.first, this->length_.second); return true; },
                            [this](const std::string_view& f) { if (boost::lexical_cast<bool>(f)) std::swap(this->length_.first, this->length_.second); return true; }
                        )
                    )
                );

                this->parser_(std::forward<T>(value), [&](const auto& arg, const auto& head, auto&& value) {
                    return commander::tuple_visit_disjunction([&](const auto& storage) {
                        if (storage.match(arg, head))
                            return storage.apply(value);
                        return false;
                    }, tup);
                });
            }
            return *this;
        }

    private:
        commander::basic_parser<std::string_view, std::string> parser_;
        std::pair<length_type, length_type> length_ = std::pair<length_type, length_type>(0, 0);
        char fill_ = char(' ');
};

int main(int /*argc*/, const char ** /*argv*/)
{
    try {
        rectangle_painter<int> rp;

        // Let's set x to 8, y to 3, use 'x' as filling character and execute. Then let's invert, set y to 4 and execute again.
        rp << "-x=8" << "-y=3" << "--fill=x" << commander::exec<>() << "-iy=4" << commander::exec<>();
    }
    catch(...) {
        std::cout << "Whooops..." << '\n';
        return 1;
    }
}
```

### rectangle_painter program argument matching
You probably noticed that we use strings to match options. So the question is: can you use commander to parse program options?
```cpp
#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <string_view>
#include <utility>

#include <boost/lexical_cast.hpp>
#include <commander.hpp>

template <typename Length>
class rectangle_painter
{
    public:
        using length_type = Length;

        template <typename... Types>
        void operator ()(Types&&... values)
        {
            if constexpr (sizeof...(values) != 0)
                ((*this) << values << ...);

            this->parser_();
            for (length_type y = 0; y < this->length_.second; ++y) {
                for (length_type x = 0; x < this->length_.first; ++x)
                    std::cout << this->fill_;
                std::cout << '\n';
            }
            std::cout << std::flush;
        }

        template <typename T>
        rectangle_painter<length_type>& operator <<(T&& value)
        {
            if constexpr (commander::func::is_exec_v(value)) {
                value(*this);
            }
            else {
                auto tup = std::make_tuple(
                    commander::make_empty_storage(
                        commander::no_value,
                        [](const std::string_view& header) { return commander::compare_disjunction(header, "-x", "-w", "--width"); },
                        commander::make_applier(
                            [this](const width_option<length_type>& xl) { this->length_.first = xl.length; return true; },
                            [this](const length_type& xl) { this->length_.first = xl; return true; },
                            [this](const std::string_view& xl) { this->length_.first = boost::lexical_cast<length_type>(xl); return true; }
                        )
                    ),
                    commander::make_empty_storage(
                        commander::no_value,
                        [](const std::string_view& header) { return commander::compare_disjunction(header, "-y", "-h", "--height"); },
                        commander::make_applier(
                            [this](const height_option<length_type>& yl) { this->length_.second = yl.length; return true; },
                            [this](const length_type& yl) { this->length_.second = yl; return true; },
                            [this](const std::string_view& yl) { this->length_.second = boost::lexical_cast<length_type>(yl); return true; }
                        )
                    ),
                    commander::make_empty_storage(
                        commander::no_value,
                        [](const std::string_view& header) { return commander::compare_disjunction(header, "-f", "--fill"); },
                        commander::make_applier(
                            [this](const fill_option& f) { this->fill_ = f.character; return true; },
                            [this](const char& f) { this->fill_ = f; return true; },
                            [this](const std::string_view& f) { this->fill_ = boost::lexical_cast<char>(f); return true; }
                        )
                    ),
                    commander::make_empty_storage(
                        commander::no_value,
                        [](const std::string_view& header) { return commander::compare_disjunction(header, "-i", "--inv", "--invert"); },
                        commander::make_applier(
                            [this](const invert_option&) { std::swap(this->length_.first, this->length_.second); return true; },
                            commander::make_type_applier<commander::type_list<commander::no_value_t, commander::placeholder_t>>(
                                [this]() { std::swap(this->length_.first, this->length_.second); return true; }
                            ),
                            [this](const bool& i) { if (i) std::swap(this->length_.first, this->length_.second); return true; },
                            [this](const std::string_view& f) { if (boost::lexical_cast<bool>(f)) std::swap(this->length_.first, this->length_.second); return true; }
                        )
                    )
                );

                this->parser_(std::forward<T>(value), [&](const auto& arg, const auto& head, auto&& value) {
                    return commander::tuple_visit_disjunction([&](const auto& storage) {
                        if (storage.match(arg, head))
                            return storage.apply(value);
                        return false;
                    }, tup);
                });
            }
            return *this;
        }

    private:
        commander::basic_parser<std::string_view, std::string> parser_;
        std::pair<length_type, length_type> length_ = std::pair<length_type, length_type>(0, 0);
        char fill_ = char(' ');
};

int main(int argc, const char ** argv)
{
    try {
        rectangle_painter<int> rp;

        std::for_each(argv + 1, argv + argc, [&](const char* str) { rp << str; });

        rp();
    }
    catch(...) {
        std::cout << "Whooops..." << '\n';
        return 1;
    }
}
```

### rectangle_painter zero overhead matching
It is worth notice that matching is based on strings, so it is some computational overhead. We can overcome this by introducing option types.

There are many ways to accomplish this. The example below uses storage metadata to keep a type_list.
```cpp
#include <array>
#include <iostream>
#include <string>
#include <string_view>
#include <utility>

#include <boost/lexical_cast.hpp>
#include <commander.hpp>

template <typename Length>
struct width_option { Length length; };

template <typename Length>
struct height_option { Length length; };

struct fill_option { char character; };

struct invert_option {};

template <typename Length>
class rectangle_painter
{
    public:
        using length_type = Length;

        template <typename... Types>
        void operator ()(Types&&... values)
        {
            if constexpr (sizeof...(values) != 0)
                ((*this) << values << ...);

            this->parser_();
            for (length_type y = 0; y < this->length_.second; ++y) {
                for (length_type x = 0; x < this->length_.first; ++x)
                    std::cout << this->fill_;
                std::cout << '\n';
            }
            std::cout << std::flush;
        }

        template <typename T>
        rectangle_painter<length_type>& operator <<(T&& value)
        {
            if constexpr (commander::func::is_exec_v(value)) {
                value(*this);
            }
            else {
                auto tup = std::make_tuple(
                    commander::make_empty_storage(
                        commander::type_list<width_option<length_type>>{},
                        [](const std::string_view& header) { return commander::compare_disjunction(header, "-x", "-w", "--width"); },
                        commander::make_applier(
                            [this](const width_option<length_type>& xl) { this->length_.first = xl.length; return true; },
                            [this](const length_type& xl) { this->length_.first = xl; return true; },
                            [this](const std::string_view& xl) { this->length_.first = boost::lexical_cast<length_type>(xl); return true; }
                        )
                    ),
                    commander::make_empty_storage(
                        commander::type_list<height_option<length_type>>{},
                        [](const std::string_view& header) { return commander::compare_disjunction(header, "-y", "-h", "--height"); },
                        commander::make_applier(
                            [this](const height_option<length_type>& yl) { this->length_.second = yl.length; return true; },
                            [this](const length_type& yl) { this->length_.second = yl; return true; },
                            [this](const std::string_view& yl) { this->length_.second = boost::lexical_cast<length_type>(yl); return true; }
                        )
                    ),
                    commander::make_empty_storage(
                        commander::type_list<fill_option>{},
                        [](const std::string_view& header) { return commander::compare_disjunction(header, "-f", "--fill"); },
                        commander::make_applier(
                            [this](const fill_option& f) { this->fill_ = f.character; return true; },
                            [this](const char& f) { this->fill_ = f; return true; },
                            [this](const std::string_view& f) { this->fill_ = boost::lexical_cast<char>(f); return true; }
                        )
                    ),
                    commander::make_empty_storage(
                        commander::type_list<invert_option>{},
                        [](const std::string_view& header) { return commander::compare_disjunction(header, "-i", "--inv", "--invert"); },
                        commander::make_applier(
                            [this](const invert_option&) { std::swap(this->length_.first, this->length_.second); return true; },
                            commander::make_type_applier<commander::type_list<commander::no_value_t, commander::placeholder_t>>(
                                [this]() { std::swap(this->length_.first, this->length_.second); return true; }
                            ),
                            [this](const bool& i) { if (i) std::swap(this->length_.first, this->length_.second); return true; },
                            [this](const std::string_view& f) { if (boost::lexical_cast<bool>(f)) std::swap(this->length_.first, this->length_.second); return true; }
                        )
                    )
                );

                auto type_check = [&](const auto& storage) {
                    if constexpr (commander::tl::index_of_v<std::decay_t<decltype(storage.metadata())>, std::decay_t<T>> != commander::tl::npos) {
                        storage.apply(value);
                        return true;
                    }
                    return false;
                };

                if (!commander::tuple_visit_disjunction(type_check, tup)) {
                    this->parser_(std::forward<T>(value), [&](const auto& arg, const auto& head, auto&& value) {
                        return commander::tuple_visit_disjunction([&](const auto& storage) {
                            if (storage.match(arg, head))
                                return storage.apply(value);
                            return false;
                        }, tup);
                    });
                }
            }
            return *this;
        }

    private:
        commander::basic_parser<std::string_view, std::string> parser_;
        std::pair<length_type, length_type> length_ = std::pair<length_type, length_type>(0, 0);
        char fill_ = char(' ');
};

int main(int /*argc*/, const char ** /*argv*/)
{
    try {
        rectangle_painter<int> rp;

        // Let's set x to 8, y to 3, use 'x' as filling character and execute.
        rp << width_option<int>{8} << height_option<int>{3} << fill_option{'x'} << commander::exec<>();
    }
    catch(...) {
        std::cout << "Whooops..." << '\n';
        return 1;
    }
}
```

## The command design pattern with the commander library
> Creation of this section is still in progress.

## Used third-party tools and libraries

The commander itself is a header-only library licensed under the BSL license. Note, that you do not need any third-party software to use it!

- [Boost C++ Libraries](http://www.boost.org) - for the unit tests
- [Cmake](https://cmake.org) - for build automation

## License

The commander library is open-source software licensed under the [Boost Software License 1.0](https://opensource.org/licenses/bsl1.0).
