#include <iostream>
#include <vector>
#include <print>

void
sort(std::vector<int> &arr)
{
    size_t i{}, j{};
    while (j < arr.size()) {
        if (arr.at(j) % 2 == 0) {
            int tmp = arr.at(j);
            arr.at(j) = arr.at(i);
            arr.at(i) = tmp;
            i++;
        }
        j++;
    }
}

int
main()
{
    {
        std::println("Test 1: (0, 2, 1, 0). Expected res: (0, 2, 0, 1)");

        std::vector<int> myVec1 = {0, 2, 1, 0};
        sort(myVec1);
        for (auto x : myVec1) {
            std::print("{} ", x);
        }
        std::cout << std::endl;
    }

    {
        std::println("Test 2: (2, 1, 0). Expected res: (2, 0, 1)");

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
        std::println("Test 4: (3, 2, 4, 1, 11, 8, 9). Expected res: (2, 4, 8, 1, 11, 3, 9)");

        std::vector<int> myVec1 = {3, 2, 4, 1, 11, 8, 9};
        sort(myVec1);
        for (auto x : myVec1) {
            std::print("{} ", x);
        }
        std::cout << std::endl;
    }
}
