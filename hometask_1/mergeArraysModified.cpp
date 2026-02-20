#include <iostream>
#include <print>
#include <vector>

void
merge_arrays(std::vector<int> &arr1, int m, std::vector<int> &arr2, int n)
{
    int i{m - 1};
    int j{n - 1};
    int k{m + n - 1};

    while (j >= 0) {
        if (i >= 0 && arr1[i] > arr2[j]) {
            arr1[k] = arr1[i];
            i--;
        } else {
            arr1[k] = arr2[j];
            j--;
        }
        k--;
    }
}

int
main()
{
    {
        std::println("Test 1: (2, 4, 6, 0, 0, 0), (1, 5, 7). Expected res: (1, 2, 4, 5, 6, 7)");

        std::vector<int> myVec1 = {2, 4, 6, 0, 0, 0};
        std::vector<int> myVec2 = {1, 5, 7};
        merge_arrays(myVec1, 3, myVec2, 3);

        for (auto x : myVec1) {
            std::print("{} ", x);
        }
        std::cout << std::endl;
    }

    {
        std::println("Test 2: (0, 0, 0), (1, 5, 7). Expected res: (1, 5, 7)");

        std::vector<int> myVec1 = {0, 0, 0};
        std::vector<int> myVec2 = {1, 5, 7};
        merge_arrays(myVec1, 0, myVec2, 3);

        for (auto x : myVec1) {
            std::print("{} ", x);
        }
        std::cout << std::endl;
    }
    {
        std::println("Test 3: (2, 4, 6), (). Expected res: (2, 4, 6)");

        std::vector<int> myVec1 = {2, 4, 6};
        std::vector<int> myVec2 = {};
        merge_arrays(myVec1, 3, myVec2, 0);

        for (auto x : myVec1) {
            std::print("{} ", x);
        }
        std::cout << std::endl;
    }
}
