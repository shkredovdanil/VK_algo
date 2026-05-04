#include <vector>
#include <unordered_map>

int
findMaxLength(const std::vector<int> &nums)
{
    std::unordered_map<int, int> firstOccurrence;
    firstOccurrence[0] = -1;

    int currentSum = 0;
    int maxLen = 0;

    for (int i = 0; i < nums.size(); ++i) {
        currentSum += (nums[i] == 1 ? 1 : -1);
        if (firstOccurrence.find(currentSum) != firstOccurrence.end()) {
            maxLen = std::max(maxLen, i - firstOccurrence[currentSum]);
        } else {
            firstOccurrence[currentSum] = i;
        }
    }
    return maxLen;
}
