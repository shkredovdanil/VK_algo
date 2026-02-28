#include <iostream>
#include <print>

int
make_unique(int *arr, int n) // return amount of unique elem. Those elem. are located on first k pos.
{
    if (!arr) {
        return 0;
    }

    int slow = 0;

    for (int fast = 1; fast < n; fast++) {
        if (arr[slow] != arr[fast]) {
            slow++;
            arr[slow] = arr[fast];
        }
    }

    return slow + 1;
}

int
main()
{
    {
        std::println("Test 1: [1, 2, 3, 4]. Expect: [1, 2, 3, 4]");
        int arr[] = {1, 2, 3, 4};
        int k = make_unique(arr, sizeof(arr) / sizeof(*arr));

        for (int i = 0; i < k; i++) {
            std::print("{} ", arr[i]);
        }
        std::println();
    }
    {
        std::println("Test 2: [1, 2, 2, 4]. Expect: [1, 2, 4]");
        int arr[] = {1, 2, 2, 4};
        int k = make_unique(arr, sizeof(arr) / sizeof(*arr));

        for (int i = 0; i < k; i++) {
            std::print("{} ", arr[i]);
        }
        std::println();
    }
    {
        std::println("Test 3: [1, 1]. Expect: [1]");
        int arr[] = {1, 1};
        int k = make_unique(arr, sizeof(arr) / sizeof(*arr));

        for (int i = 0; i < k; i++) {
            std::print("{} ", arr[i]);
        }
        std::println();
    }
    {
        std::println("Test 4: [1, 1, 2, 2]. Expect: [1, 2]");
        int arr[] = {1, 1, 2, 2};
        int k = make_unique(arr, sizeof(arr) / sizeof(*arr));

        for (int i = 0; i < k; i++) {
            std::print("{} ", arr[i]);
        }
        std::println();
    }
}
