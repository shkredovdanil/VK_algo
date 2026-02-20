#include <iostream>
#include <print>
#include <vector>

void
sort(std::vector<int> &arr)
{
    int i{}, j(arr.size() - 1);
    while (i < j) {
        if (arr.at(j) == 1) { // (0, 1), (1, 1)
            j--;
        } else if (arr.at(i) - arr.at(j) == 1) { // (1, 0)
            int tmp = arr.at(j);
            arr.at(j) = arr.at(i);
            arr.at(i) = tmp;
            i++;
            j--;
        } else { // (0, 0)
            i++;
        }
    }
}

int
main()
{
    {
        std::println("Test 1: (0, 0, 1, 0). Expected res: (0, 0, 0, 1)");

        std::vector<int> myVec1 = {0, 0, 1, 0};
        sort(myVec1);
        for (auto x : myVec1) {
            std::print("{} ", x);
        }
        std::cout << std::endl;
    }

    {
        std::println("Test 2: (1, 0). Expected res: (0, 1)");

        std::vector<int> myVec1 = {1, 0};
        sort(myVec1);
        for (auto x : myVec1) {
            std::print("{} ", x);
        }
        std::cout << std::endl;
    }
    {
        std::println("Test 3: (1). Expected res: (1)");

        std::vector<int> myVec1 = {1};
        sort(myVec1);
        for (auto x : myVec1) {
            std::print("{} ", x);
        }
        std::cout << std::endl;
    }
}
