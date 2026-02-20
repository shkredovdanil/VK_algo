#include <iostream>
#include <vector>
#include <print>

void
sort(std::vector<int> &arr)
{
    int l{}, mid{}, r(arr.size() - 1);
    while (mid <= r) {
        if (arr.at(mid) == 2) {
            int tmp(arr.at(mid));
            arr.at(mid) = arr.at(r);
            arr.at(r) = tmp;
            r--;
        } else if (arr.at(mid) == 0) {
            int tmp(arr.at(mid));
            arr.at(mid) = arr.at(l);
            arr.at(l) = tmp;
            l++;
            mid++;
        } else {
            mid++;
        }
    }
}

int
main()
{
    {
        std::println("Test 1: (0, 2, 1, 0). Expected res: (0, 0, 1, 2)");

        std::vector<int> myVec1 = {0, 2, 1, 0};
        sort(myVec1);
        for (auto x : myVec1) {
            std::print("{} ", x);
        }
        std::cout << std::endl;
    }

    {
        std::println("Test 2: (2, 1, 0). Expected res: (0, 1, 2)");

        std::vector<int> myVec1 = {2, 1, 0};
        sort(myVec1);
        for (auto x : myVec1) {
            std::print("{} ", x);
        }
        std::cout << std::endl;
    }
    {
        std::println("Test 3: (0, 1). Expected res: (0, 1)");

        std::vector<int> myVec1 = {0, 1};
        sort(myVec1);
        for (auto x : myVec1) {
            std::print("{} ", x);
        }
        std::cout << std::endl;
    }
    {
        std::println("Test 4: (1, 0). Expected res: (0, 1)");

        std::vector<int> myVec1 = {1, 0};
        sort(myVec1);
        for (auto x : myVec1) {
            std::print("{} ", x);
        }
        std::cout << std::endl;
    }
}
