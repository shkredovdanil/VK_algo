#include <vector>
#include <iostream>

unsigned
max_incresing_len(const std::vector<int> &vec)
{
    std::vector<unsigned> tmp = {1};

    unsigned max{1};
    for (size_t i = 1; i < vec.size(); i++) {
        if (vec[i] > vec[i - 1]) {
            tmp.push_back(tmp[i - 1] + 1);

            if (tmp.back() > max) {
                max = tmp.back();
            }
        } else {
            tmp.push_back(1);
        }
    }

    return max;
}

/*
    Делаем массив, каждый элемент которого показывает
    длинну возрастающей последовательности до этого элемента

    Одновременно с этим находим максимум
*/

int
main()
{
    // Тест 1: Обычный случай из примера
    std::vector<int> test1 = {3, 2, 8, 9, 5, 10};
    std::cout << "Test 1 [3, 2, 8, 9, 5, 10]: " << (max_incresing_len(test1) == 3 ? "PASSED" : "FAILED")
              << " (Result: 3)" << std::endl;

    // Тест 2: Длинная цепочка в начале
    std::vector<int> test2 = {1, 2, 7, 9, 0, 10};
    std::cout << "Test 2 [1, 2, 7, 9, 0, 10]: " << (max_incresing_len(test2) == 4 ? "PASSED" : "FAILED")
              << " (Result: 4)" << std::endl;

    // Тест 3: Все числа одинаковые
    std::vector<int> test3 = {8, 8, 8, 8};
    std::cout << "Test 3 [8, 8, 8, 8]: " << (max_incresing_len(test3) == 1 ? "PASSED" : "FAILED") << " (Result: 1)"
              << std::endl;

    // Тест 4: Строго убывающая последовательность
    std::vector<int> test4 = {5, 4, 3, 2, 1};
    std::cout << "Test 4 [5, 4, 3, 2, 1]: " << (max_incresing_len(test4) == 1 ? "PASSED" : "FAILED") << " (Result: 1)"
              << std::endl;

    // Тест 5: Весь массив — одна возрастающая последовательность
    std::vector<int> test5 = {1, 2, 3, 4, 5};
    std::cout << "Test 5 [1, 2, 3, 4, 5]: " << (max_incresing_len(test5) == 5 ? "PASSED" : "FAILED") << " (Result: 5)"
              << std::endl;

    return 0;
}
