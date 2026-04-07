#include "heap.hpp"
#include <vector>

std::vector<int> sort_arrays(std::vector<std::vector<int>> arr) {
    MinHeap minheap; 
    for (int i = 0; i < arr.size(); ++i) {
        for (int j = 0; j < arr[i].size(); ++j) {
            minheap.insert(arr[i][j]);
        }
    } 

    std::vector<int> res;
    while (!minheap.empty()) {
        res.push_back(minheap.extractMin());
    }

    return res;
}

/*
    Сложноть алгоритма O(n*logn). N - элементов. Сложность вставки в min кучу элемента - log n
*/
