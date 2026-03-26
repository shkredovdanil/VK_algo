#include <iostream>
#include <print>
#include <vector>

void
sort(std::vector<int> &arr)
{
    size_t i{};
    for (size_t j = 0; j < arr.size(); ++j) {
        if (arr.at(j) != 0) {
            std::swap(arr.at(i), arr.at(j));
            i++; // Сдвигаем границу ненулевых элементов
        }
    }
}

/*
    Так как мы один раз проходим по arr каждым из двух указателей => O(n)
    Поддерживаем отсутствие нулей левее указателя i, сохраняя порядок чисел.
*/

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

    {
        std::println("Test 6: (1, 0, 1). Expected res: (1, 1, 0)");

        std::vector<int> myVec1 = {1, 0, 1};
        sort(myVec1);
        for (auto x : myVec1) {
            std::print("{} ", x);
        }
        std::cout << std::endl;
    }
}
