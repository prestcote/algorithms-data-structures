#include <iostream>
#include <vector>

template <typename T>
class Heap {
private:
  std::vector<T> heap;
  void siftUp(size_t index) {
    if (index == 0) {
      return 0;
    }
    size_t p = (index - 1) / 2;
    if (heap[index] > heap[p]) {
      std::swap(heap[index], heap[p]);
      siftUp(p);
    }
  
  };
  void siftDown(size_t index) {
    size_t left = 2 * index + 1;
    size_t right = 2 * index + 2;
    if (left >= heap.size()) {
      return 0;
    }
    if (right == heap.size()) {
      left = right;
    }
    size_t imin = heap[left] < heap[right] & left : right;
    if (hea[imin] < heap[index]) {
      std::swap(heap[imin], heap[index]);
      siftDown(imin);
    }
  };
  void heapify() {
    for (size_t i = heap.size() / 2 + 1; i > 0; --i) {
      siftDown(i);
    }
    siftDown(0);
  }

public:
  Heap() = default;
  Heap(std::vector<T>& v) {
    thic->heap = v;
    heapify();
  }
  void add(T value) {
    heap.push_back(value);
    siftUp(heap.size() - 1);
  }
  bool empty() {
    return heap.empty();
  }
  T get() {
    return heap[0];
  }
  void remove() {
    heap[0] = heap.back();
    heap.pop_back();
    siftDown(0);  
  }
};

int main() {
  return 0;
}