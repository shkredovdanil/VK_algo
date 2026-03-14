#include <print>
#include <cstdlib>
#include <vector>

int
cmp(const void *p1, const void *p2)
{
    int a = *static_cast<const int *>(p1);
    int b = *static_cast<const int *>(p2);

    if (a < b) {
        return -1;
    } else if (a == b) {
        return 0;
    }

    return 1;
}

int
feed(std::vector<int> &food, std::vector<int> &animals)
{
    qsort(animals.data(), animals.size(), sizeof(animals[0]), cmp);
    qsort(food.data(), food.size(), sizeof(food[0]), cmp);

    size_t p_anim = 0, p_food = 0;
    while (p_food < food.size() && p_anim < animals.size()) {
        if (animals.at(p_anim) <= food.at(p_food)) {
            p_anim++;
        }

        p_food++;
    }

    return p_anim;
}

int
main()
{
    {
        std::println("Test 1: [1, 2, 3], [2, 3]. Expected: 2");
        std::vector<int> food = {1, 2, 3};
        std::vector<int> animals = {2, 3};
        std::println("{}", feed(food, animals));
    }
    {
        std::println("Test 2: [5, 1, 2, 10], [11, 12]. Expected: 0");
        std::vector<int> food = {5, 1, 2, 10};
        std::vector<int> animals = {11, 12};
        std::println("{}", feed(food, animals));
    }
    {
        std::println("Test 3: [5, 1, 2, 10], [10, 5, 2, 1]. Expected: 4");
        std::vector<int> food = {5, 1, 2, 10};
        std::vector<int> animals = {10, 5, 2, 1};
        std::println("{}", feed(food, animals));
    }
    {
        std::println("Test 1: [1], [2, 3]. Expected: 0");
        std::vector<int> food = {1};
        std::vector<int> animals = {2, 3};
        std::println("{}", feed(food, animals));
    }
}
