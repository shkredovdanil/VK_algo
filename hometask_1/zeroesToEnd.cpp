#include <iostream>
#include <print>
#include <vector>

void
sort(std::vector<int> &arr)
{
    size_t i{}, j{};
    while (j < arr.size()) { // левее arr[i] - нулей нет
        if (arr.at(i) == 0 && arr.at(j) != 0) {
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
        std::println("Test 1: (0, 2, 1, 0). Expected res: (2, 1, 0, 0)");

        std::vector<int> myVec1 = {0, 2, 1, 0};
        sort(myVec1);
        for (auto x : myVec1) {
            std::print("{} ", x);
        }
        std::cout << std::endl;
    }

    {
        std::println("Test 2: (2, 1, 0). Expected res: (2, 1, 0)");

        std::vector<int> myVec1 = {2, 1, 0};
        sort(myVec1);
        for (auto x : myVec1) {
            std::print("{} ", x);
        }
        std::cout << std::endl;
    }
    {
        std::println("Test 3: (0, 1). Expected res: (1, 0)");

        std::vector<int> myVec1 = {0, 1};
        sort(myVec1);
        for (auto x : myVec1) {
            std::print("{} ", x);
        }
        std::cout << std::endl;
    }
    {
        std::println("Test 4: (1, 0). Expected res: (1, 0)");

        std::vector<int> myVec1 = {1, 0};
        sort(myVec1);
        for (auto x : myVec1) {
            std::print("{} ", x);
        }
        std::cout << std::endl;
    }
    {
        std::println("Test 5: (0, 2, 1, 0, 5, 0). Expected res: (2, 1, 5, 0, 0, 0)");

        std::vector<int> myVec1 = {0, 2, 1, 0, 5, 0};
        sort(myVec1);
        for (auto x : myVec1) {
            std::print("{} ", x);
        }
        std::cout << std::endl;
    }
}
