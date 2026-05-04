#include <vector>

int findMinIndex(const std::vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    if (nums[left] <= nums[right]) return left;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (mid > 0 && nums[mid] < nums[mid - 1]) return mid;
        
        if (nums[mid] >= nums[left]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return 0;
}