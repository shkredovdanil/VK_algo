#include <unordered_map>
#include <vector>

int
subarraySumEqualsK(const std::vector<int> &nums, int k)
{
    std::unordered_map<long long, int> prefCounts;
    prefCounts[0] = 1;

    long long currentSum = 0;
    int count = 0;

    for (int num : nums) {
        currentSum += num;
        if (prefCounts.find(currentSum - k) != prefCounts.end()) {
            count += prefCounts[currentSum - k];
        }
        prefCounts[currentSum]++;
    }
    return count;
}

/*
Здесь мы используем std::unordered_map для хранения частоты встречаемости префиксных сумм. Если текущая префиксная сумма
sum, а мы ищем подмассив с суммой k, нам нужно проверить, сколько раз до этого встречалась сумма sum - k.
*/
