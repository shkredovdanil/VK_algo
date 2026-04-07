#include <vector>
#include "heap.hpp"

int
findKthLargest(const std::vector<int> &arr, int k)
{
    if (k <= 0 || k > arr.size()) {
        throw std::invalid_argument("Invalid k");
    }

    MinHeap minheap;

    for (int num : arr) {
        if (minheap.size() < k) {
            minheap.insert(num);
        } else if (num > minheap.getMin()) {
            minheap.extractMin();
            minheap.insert(num);
        }
    }

    return minheap.getMin();
}


/*
вставка первых k элементов - k*logk
Далее (n-k)logk
Итого n * logk
*/