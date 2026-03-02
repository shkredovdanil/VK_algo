#include <iostream>
#include <vector>
#include <print>

auto
merge_arrays(std::vector<int> &arr1, std::vector<int> &arr2) -> std::vector<int>
{
    size_t i{}, j{};
    std::vector<int> res;
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1.at(i) < arr2.at(j)) {
            res.push_back(arr1.at(i));
            i++;
        } else {
            res.push_back(arr2.at(j));
            j++;
        }
    }
    while (i < arr1.size()) {
        res.push_back(arr1.at(i));
        i++;
    }
    while (j < arr2.size()) {
        res.push_back(arr2.at(j));
        j++;
    }

    return res;
}

int
main()
{
    {
        std::println("Test 1: (2, 4, 6), (1, 5, 7). Expected res: (1, 2, 4, 5, 6, 7)");

        std::vector<int> myVec1 = {2, 4, 6};
        std::vector<int> myVec2 = {1, 5, 7};
        std::vector<int> res = merge_arrays(myVec1, myVec2);
        for (auto x : res) {
            std::print("{} ", x);
        }
        std::cout << std::endl;
    }

    {
        std::println("Test 2: (2, 4, 6), (1). Expected res: (1, 2, 4, 6)");

        std::vector<int> myVec1 = {2, 4, 6};
        std::vector<int> myVec2 = {1};
        std::vector<int> res = merge_arrays(myVec1, myVec2);
        for (auto x : res) {
            std::print("{} ", x);
        }
        std::cout << std::endl;
    }
    {
        std::println("Test 3: (2, 4, 6), (). Expected res: (2, 4, 6)");

        std::vector<int> myVec1 = {2, 4, 6};
        std::vector<int> myVec2 = {};
        std::vector<int> res = merge_arrays(myVec1, myVec2);
        for (auto x : res) {
            std::print("{} ", x);
        }
        std::cout << std::endl;
    }
}
