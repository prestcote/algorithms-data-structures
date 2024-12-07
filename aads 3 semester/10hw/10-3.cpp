#include<iostream>
#include<vector>
#include <string>
#include <algorithm>
#include <iomanip>

template<typename T>
class Heap {
private:
  std::vector<T> heap;

  void siftUp(size_t index) {
    if (index == 0) return;
    size_t p = (index - 1) / 2;
    if (heap[index] < heap[p]) {
      std::swap(heap[index], heap[p]);
      siftUp(p);
    }
  }

  void siftDown(size_t index) {
    size_t left = 2 * index + 1;
    size_t right = 2 * index + 2;
    if (right > heap.size()) return;
    if (right == heap.size()) {
      right = left;
    }
    size_t imin = (heap[left] <= heap[right]) ? left : right;
    if (heap[imin] < heap[index]) {
      std::swap(heap[imin], heap[index]);
      siftDown(imin);
    }
  }

  void heapify() {
    for (size_t i = heap.size() / 2 + 1; i > 0; --i) {
      siftDown(i);
    }
    siftDown(0);
  }

public:
  Heap() = default;
  Heap(std::vector<T>& v) {
    this->heap = v;
    if (v.size() > 0) heapify();
  }
  void add(T value) {
    heap.push_back(value);
    siftUp(heap.size() - 1);
  }

  bool empty() {
    return heap.empty();
  }

  T size() {
    return heap.size();
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
  int n = 0;
  std::cin >> n;
  std::vector<long long> v(n);
  for (int i = 0; i < n; i++) {
    std::cin >> v[i];
  }
  Heap<long long> h(v);
  long long a = 0;
  long long b = 0;
  double sum = 0;
  while (h.size() != 1) {
    a = h.get();
    h.remove();
    b = h.get();
    h.remove();
    h.add(a + b);
    sum += (a + b) * 0.05;
  }
  std::cout << std::fixed << std::setprecision(2) << sum;
  return 0;
}