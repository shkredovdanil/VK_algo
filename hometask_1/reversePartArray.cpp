#include <iostream>
#include <vector>
#include <print>

void
reverse_array(std::vector<int> &arr, int l, int r)
{
    for (int i{l}, j{r}; i < j; i++, j--) {
        int tmp{};
        tmp = arr.at(j);
        arr.at(j) = arr.at(i);
        arr.at(i) = tmp;
    }
}

void
solution(std::vector<int> &arr, int n)
{
    reverse_array(arr, 0, arr.size() - 1);
    reverse_array(arr, 0, n % arr.size() - 1);
    reverse_array(arr, n % arr.size(), arr.size() - 1);
}

int
main()
{

    {
        std::println("Test 1: (2, 4, 6), 1. Expected res: (6, 2, 4)");

        std::vector<int> myVec = {2, 4, 6};
        solution(myVec, 1);
        for (auto x : myVec) {
            std::print("{} ", x);
        }
        std::cout << std::endl;
    }

    {
        std::println("Test 2: (2, 4, 6), 0. Expected res: (2, 4, 6)");

        std::vector<int> myVec = {2, 4, 6};
        solution(myVec, 0);
        for (auto x : myVec) {
            std::print("{} ", x);
        }
        std::cout << std::endl;
    }

    {
        std::println("Test 3: (2, 4, 6), 6. Expected res: (2, 4, 6)");

        std::vector<int> myVec = {2, 4, 6};
        solution(myVec, 6);
        for (auto x : myVec) {
            std::print("{} ", x);
        }
        std::cout << std::endl;
    }

    return 0;
}
