#include <iostream>
#include <vector>
#include <map>

template<typename T>
class SegmentTree {
private:
  T* arr_;
  T* tree_;
  size_t size_ = 0;
  size_t limit_ = 1;

  void build(size_t v, size_t left, size_t right) {
    if (left + 1 == right && left < size_) {
      tree_[v] = arr_[left];
    }
    else if (left + 1 == right) {
      tree_[v] = 0;
    }
    else {
      size_t mid = (left + right) / 2;
      build(2 * v + 1, left, mid);
      build(2 * v + 2, mid, right);
      tree_[v] = tree_[2 * v + 1] + tree_[2 * v + 2];
    }
  }

  T get(size_t v, size_t left, size_t right, size_t qleft, size_t qright) {
    if (qleft <= left && right <= qright) {
      return tree_[v];
    }
    else if (qleft > right || qright < left) {
      return 0;
    }
    else {
      size_t mid = (left + right) / 2;
      return get(2 * v + 1, left, mid) + get(2 * v + 2, mid, right);
    }
  }

  void set(size_t v, size_t left, size_t right, size_t index, T value) {
    if (left + 1 == right && left < size_) {
      arr_[left] = value;
      tree_[v] = value;
    }
    else if (left + 1 == right) {
      return 0;
    }
    else {
      size_t mid = (left + right) / 2;
      if (index < mid) {
        set(2 * v + 1, left, mid);
      }
      else {
        set(2 * v + 2, mid, right);
      }
      tree_[v] = tree_[2 * v + 1] + tree_[2 * v + 2];
    }
  }

public:
  SegmentTree(T* arr, size_t size) {
    size_ = size;
    arr_ = new T[size];
    for (size_t i = 0; i < size; i++) {
      arr_[i] = arr[i];
    }
    tree_ = new T[4 * size];
    while (limit_ < size) {
      limit_ <<= 1;
    }
    build(0, 0, limit_);
  }

  ~SegmentTree() {
    delete[] tree_;
    delete[] arr_;
  }

  void set(size_t index, T value) {
    set(0, 0, limit_, index, value);
  }

  T get(size_t left, size_t right) {
    return get(0, 0, limit_, left, right);
  }
};

int main() {
  long long n = 0;
  std::cin >> n;
  long long* arr = new long long[n];
  std::map<long long, std::vector<long long>> k;
  long long a = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> a;
    arr[i] = a;
    k[a].push_back(i);
  }
  SegmentTree<long long> st(arr, n);

}