#include <vector>
#include <algorithm>

long long
maxSubarraySumK(const std::vector<int> &arr, int k)
{
    int n = arr.size();
    if (n < k) {
        return 0;
    }

    std::vector<long long> pref(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + arr[i];
    }

    long long maxSum = -1e18;
    for (int i = k; i <= n; ++i) {
        maxSum = std::max(maxSum, pref[i] - pref[i - k]);
    }
    return maxSum;
}

/*
Префиксные суммы позволяют вычислить сумму на любом отрезке [i,j] за O(1) как P[j]−P[i−1].
*/
