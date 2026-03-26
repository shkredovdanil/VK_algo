#include <print>

unsigned
sqrt(unsigned x)
{
    if (x < 2) {
        return x;
    }

    unsigned left{1}, right{x};
    unsigned mid{};

    while (left <= right) {
        mid = (left + right) / 2;

        if (mid <= x / mid) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return right;
}

/*
Бин поиск => log(n)
*/

int
main()
{
    using std::println;
    {
        println("Test 1: Input 25, Expected output 5");
        println("{}", sqrt(25));
    }
    {
        println("Test 2: Input 1, Expected output 1");
        println("{}", sqrt(1));
    }
    {
        println("Test 3: Input 29, Expected output 5");
        println("{}", sqrt(29));
    }
    {
        println("Test 4: Input 63, Expected output 7");
        println("{}", sqrt(63));
    }
    {
        println("Test 5: Input 5, Expected output 2");
        println("{}", sqrt(5));
    }
    {
        println("Test 6: Input 6, Expected output 2");
        println("{}", sqrt(6));
    }
    {
        println("Test 7: Input 7, Expected output 2");
        println("{}", sqrt(7));
    }
    {
        println("Test 8: Input 8, Expected output 2");
        println("{}", sqrt(8));
    }
    {
        println("Test 9: Input 9, Expected output 3");
        println("{}", sqrt(9));
    }
    {
        println("Test 10: Input 4, Expected output 2");
        println("{}", sqrt(4));
    }
}
