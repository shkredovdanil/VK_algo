#include <cstddef>
#include <print>
#include <vector>
#include <unordered_map>

std::vector<int>
twoSum(const std::vector<int> &data, int target)
{
    std::unordered_map<int, int> cache;

    for (size_t i = 0; i < data.size(); i++) {
        cache[data[i]] = i;
    }

    for (size_t i = 0; i < data.size(); i++) {
        int diff = target - data[i];

        if (cache.count(diff) && cache[diff] != static_cast<int>(i)) {
            return {static_cast<int>(i), cache[diff]};
        }
    }

    return {-1, -1};
}

int
main()
{
    {
        std::println("Test 1: Input [1, 2, 3] 5, Expected output [1, 2]");
        std::vector<int> arr = {1, 2, 3};
        std::vector<int> res = twoSum(arr, 5);
        std::println("[{}, {}]", res[0], res[1]);
    }
    {
        std::println("Test 2: Input [2, 7, 11, 15] 9, Expected output [0, 1]");
        std::vector<int> arr = {2, 7, 11, 15};
        std::vector<int> res = twoSum(arr, 9);
        std::println("[{}, {}]", res[0], res[1]);
    }

    {
        std::println("Test 3: Input [3, 2, 4] 6, Expected output [1, 2]");
        std::vector<int> arr = {3, 2, 4};
        std::vector<int> res = twoSum(arr, 6);
        std::println("[{}, {}]", res[0], res[1]);
    }

    {
        std::println("Test 4: Input [3, 3] 6, Expected output [0, 1]");
        std::vector<int> arr = {3, 3};
        std::vector<int> res = twoSum(arr, 6);
        std::println("[{}, {}]", res[0], res[1]);
    }

    {
        std::println("Test 5: Input [1, 5, 3, 7] 8, Expected output [0, 3]");
        std::vector<int> arr = {1, 5, 3, 7};
        std::vector<int> res = twoSum(arr, 8);
        std::println("[{}, {}]", res[0], res[1]);
    }

    {
        std::println("Test 6: Input [10, -2, 4, 6] 4, Expected output [1, 3]");
        std::vector<int> arr = {10, -2, 4, 6};
        std::vector<int> res = twoSum(arr, 4);
        std::println("[{}, {}]", res[0], res[1]);
    }

    {
        std::println("Test 7: Input [0, 4, 3, 0] 0, Expected output [0, 3]");
        std::vector<int> arr = {0, 4, 3, 0};
        std::vector<int> res = twoSum(arr, 0);
        std::println("[{}, {}]", res[0], res[1]);
    }
}
