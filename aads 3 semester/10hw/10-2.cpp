#include<iostream>
#include<vector>
#include <string>

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

  T get() {
    return heap[0];
  }

  void remove() {
    heap[0] = heap.back();
    heap.pop_back();
    siftDown(0);
  }

  void decrease(T x, T y) {
    T index = 0;
    for (int i = 0; i < heap.size(); i++) {
      if (heap[i] == x) {
        index = i;
        heap[i] = y;
        break;
      }
    }
    siftUp(index);
  }
};

int main() {
  Heap<long long> h;
  int n = 0;
  std::cin >> n;
  std::string command;
  for (int i = 0; i < n; ++i) {
    std::cin >> command;
    if (command == "insert") {
      long long num = 0;
      std::cin >> num;
      h.add(num);
    }
    else if (command == "getMin") {
      std::cout << h.get() << ' ';
    }
    else if (command == "extractMin") {
      std::cout << h.get() << ' ';
      h.remove();
    }
    else {
      long long x = 0;
      long long y = 0;
      std::cin >> x >> y;
      h.decrease(x, y);
    }
  }

  return 0;
}