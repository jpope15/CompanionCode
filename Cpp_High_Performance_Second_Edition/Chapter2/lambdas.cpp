#include <iostream>
#include <algorithm>
#include <type_traits>

class Example {
public:
    auto member_function() {
        int a;
        // capture all variables by copy
        auto lambda_0 = [=] () { std::cout << a << std::endl; };

        // capture all variables by reference
        auto lambda_1 = [&] () { std::cout << a << std::endl; };

        // capture object by copy
        auto lambda_2 = [*this] () { std::cout << m_ << std::endl; };

        // capture object by reference
        auto lambda_3 = [this] () { std::cout << m_ << std::endl; };
    }

private:
    int m_;
};

int main () {
    int a,b,c;

    // capture a,b,c by value
    auto lambda_0 = [=] () { std::cout << a << b << c << std::endl; };

    // capture a,b,c by reference
    auto lambda_1 = [&] () { std::cout << a << b << c << std::endl; };

    // capture a,b by value, c by reference
    auto lambda_2 = [=,&c] () { std::cout << a << b << c << std::endl; };

    // capture a,b by reference, c by value
    auto lambda_3 = [&,c] () { std::cout << a << b << c << std::endl; };


    /********** LAMBDA TYPES **********/
    auto x = [] {}; // a lambda without captures
    auto y = x;     // assignable
    decltype(y) z;  // default-constructable
    static_assert(std::is_same_v<decltype(x), decltype(y)>); // passes
    static_assert(std::is_same_v<decltype(x), decltype(z)>); // passes


}