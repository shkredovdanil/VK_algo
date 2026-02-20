#include <iostream>
#include <vector>
#include <print>

void reverse_array(std::vector<int> &arr) {
    for (int i{}, j(arr.size() - 1); i < j; i++, j--) {
        int tmp{};
        tmp = arr.at(j);
        arr.at(j) = arr.at(i);
        arr.at(i) = tmp;
    }
}

int
main()
{

    {
        std::println("Test 1: (2, 4, 6). Expected res: (6, 4, 2)");

        std::vector<int> myVec = {2, 4, 6};
        reverse_array(myVec);
        for (auto x : myVec) {
            std::print("{} ", x);
        }
        std::cout << std::endl;
    }

    {
        std::println("Test 2: (1, 3, 2, 1). Expected res: (1, 2, 3, 1)");

        std::vector<int> myVec = {1, 3, 2, 1};
        reverse_array(myVec);
        for (auto x : myVec) {
            std::print("{} ", x);
        }
        std::cout << std::endl;
    }

    {
        std::println("Test 2: (1). Expected res: (1)");

        std::vector<int> myVec = {1};
        reverse_array(myVec);
        for (auto x : myVec) {
            std::print("{} ", x);
        }
        std::cout << std::endl;
    }

    return 0;
}


