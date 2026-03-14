#include <algorithm>
#include <print>

int
copy_time(int n, int x, int y)
{
    int mid{};
    int left{0}, right{std::max(x, y) * (n - 1)};

    while (left + 1 < right) {
        mid = (left + right) / 2;
        if (mid / x + mid / y < n - 1) {
            left = mid;
        } else {
            right = mid;
        }
    }

    return right + std::min(x, y);
}

int
main()
{
    using std::println;
    {
        println("Test 1. n = 1, x = 1, y = 1. Expected 1");
        println("{}", copy_time(1, 1, 1));
    }
    {
        println("Test 2. n = 2, x = 1, y = 1. Expected 2");
        println("{}", copy_time(2, 1, 1));
    }
    {
        println("Test 3. n = 3, x = 1, y = 1. Expected 2");
        println("{}", copy_time(3, 1, 1));
    }
    {
        println("Test 4. n = 4, x = 1, y = 2. Expected 3");
        println("{}", copy_time(4, 1, 2));
    }
    {
        println("Test 5. n = 5, x = 1, y = 2. Expected 4");
        println("{}", copy_time(5, 1, 2));
    }
    {
        println("Test 6. n = 10, x = 1, y = 100. Expected 10");
        println("{}", copy_time(10, 1, 100));
    }
}
