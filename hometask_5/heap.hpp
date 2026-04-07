#include <vector>
#include <stdexcept>

class MinHeap
{
  private:
    std::vector<int> heap;

    int
    parent(int index) const
    {
        return (index - 1) / 2;
    }

    int
    leftChild(int index) const
    {
        return 2 * index + 1;
    }

    int
    rightChild(int index) const
    {
        return 2 * index + 2;
    }


    bool
    hasLeftChild(int index) const
    {
        return leftChild(index) < heap.size();
    }

    bool
    hasRightChild(int index) const
    {
        return rightChild(index) < heap.size();
    }

    void
    heapifyUp(int index)
    {
        while (index > 0 && heap[parent(index)] > heap[index]) {
            std::swap(heap[parent(index)], heap[index]);
            index = parent(index);
        }
    }

    void
    heapifyDown(int index)
    {
        while (hasLeftChild(index)) {
            int largestChildIndex = leftChild(index);

            if (hasRightChild(index) && heap[rightChild(index)] < heap[leftChild(index)]) {
                largestChildIndex = rightChild(index);
            }

            if (heap[index] < heap[largestChildIndex]) {
                break;
            }

            std::swap(heap[index], heap[largestChildIndex]);
            index = largestChildIndex;
        }
    }

  public:
    MinHeap() {}

    MinHeap(const std::vector<int> &arr) : heap(arr) { buildHeap(); }

    void
    buildHeap()
    {
        for (int i = (heap.size() / 2) - 1; i >= 0; i--) {
            heapifyDown(i);
        }
    }

    void
    insert(int value)
    {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int
    extractMin()
    {
        if (heap.empty()) {
            throw std::runtime_error("Heap is empty");
        }

        int MinValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();

        if (!heap.empty()) {
            heapifyDown(0);
        }

        return MinValue;
    }

    int
    getMin() const
    {
        if (heap.empty()) {
            throw std::runtime_error("Heap is empty");
        }
        return heap[0];
    }

    int
    size() const
    {
        return heap.size();
    }

    bool
    empty() const
    {
        return heap.empty();
    }

    void
    clear()
    {
        heap.clear();
    }
};
