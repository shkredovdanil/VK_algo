#include <iostream>
#include <vector>
#include <print>

auto
twoSum(std::vector<int> &arr, int target) -> std::vector<int>
{
    int i{}, j(arr.size() - 1);
    std::vector<int> res;
    while (i < j) {
        if (arr.at(i) + arr.at(j) > target) {
            j--;
        } else if (arr.at(i) + arr.at(j) < target) {
            i++;
        } else {
            res.push_back(i);
            res.push_back(j);

            return res;
        }
    }

    res.push_back(-1);
    res.push_back(-1);

    return res;
}

int
main()
{

    {
        std::println("Test 1: (2, 4, 6), 6. Expected res: (0, 1)");

        std::vector<int> myVec = {2, 4, 6};
        std::vector<int> res = twoSum(myVec, 6);
        for (auto x : res) {
            std::print("{} ", x);
        }
        std::cout << std::endl;
    }

    {
        std::println("Test 2: (1, 3, 5, 8, 10), 8. Expected res: (1, 2)");

        std::vector<int> myVec = {1, 3, 5, 8, 10};
        std::vector<int> res = twoSum(myVec, 8);
        for (auto x : res) {
            std::print("{} ", x);
        }

        std::cout << std::endl;
    }

    {
        std::println("Test 2: (1, 3, 5, 8, 10), 18. Expected res: (3, 4)");

        std::vector<int> myVec = {1, 3, 5, 8, 10};
        std::vector<int> res = twoSum(myVec, 18);
        for (auto x : res) {
            std::print("{} ", x);
        }

        std::cout << std::endl;
    }
    return 0;
}
