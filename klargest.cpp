#include <vector>
#include <queue>

int kth_largest(std::vector<int> values, int k) {
    // The standard priority_queue is a max heap
    std::priority_queue<int> maxHeap(values.begin(), values.end());
    
    // Pop the top k-1 elements to reach the kth largest
    for (int i = 0; i < k - 1; i++) {
        if (!maxHeap.empty()) {
            maxHeap.pop();
        } else {
            throw std::runtime_error("Not enough elements in the array");
        }
    }

    if (maxHeap.empty()) {
        throw std::runtime_error("Not enough elements in the array");
    }

    return maxHeap.top();
}
