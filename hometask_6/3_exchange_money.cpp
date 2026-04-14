#include <iostream>
#include <vector>

int
exchange(const std::vector<unsigned> &coins, int amount)
{
    if (amount < 0) {
        return -1;
    }
    if (amount == 0) {
        return 0;
    }

    std::vector<int> dp(amount + 1, amount + 1);

    dp[0] = 0;

    for (int i = 1; i <= amount; ++i) {
        for (unsigned coin : coins) {
            if (i >= static_cast<int>(coin)) {
                dp[i] = std::min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    return (dp[amount] > amount) ? -1 : dp[amount];
}

void
run_test(const std::vector<unsigned> &coins, int amount, int expected, int test)
{
    int result = exchange(coins, amount);
    std::cout << "Test " << test << " ";
    if (result == expected) {
        std::cout << "PASSED";
    } else {
        std::cout << "FAILED (Expected " << expected << ", got " << result << ")";
    }
    std::cout << std::endl;
}

int
main()
{
    // Тест 1
    run_test({1, 2, 5}, 11, 3, 1);

    // Тест 2
    run_test({2}, 3, -1, 2);

    // Тест 3
    run_test({1, 2, 5}, 0, 0, 3);

    // Тест 4
    run_test({5}, 25, 5, 4);

    // Тест 5
    run_test({1, 3, 4}, 6, 2, 5);

    return 0;
}
