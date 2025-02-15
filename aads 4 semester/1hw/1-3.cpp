#include <iostream>
#include <algorithm>

template <typename T>
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
      tree_[v] = std::max(tree_[2 * v + 1],tree_[2 * v + 2]);
    }
  }

  T get(size_t v, size_t left, size_t right, size_t qleft, size_t qright) {
    if (qleft <= left && right <= qright) {
      return tree_[v];
    }
    else if (qright <= left || right <= qleft) {
      return 0;
    }
    else {
      size_t mid = (left + right) / 2;
      return std::max(get(2 * v + 1, left, mid, qleft, qright), get(2 * v + 2, mid, right, qleft, qright));
    }
  }

public:
  SegmentTree(const T* arr, size_t size) {
    arr_ = new T[size];
    size_ = size;
    for (size_t i = 0; i < size; ++i) {
      arr_[i] = arr[i];
    }
    tree_ = new T[4 * size];
    while (limit_ < size) {
      limit_ <<= 1;
    }
    build(0, 0, limit_);
  }

  void print() {
    for (size_t i = 0; i < 4 * size_; ++i) {
      std::cout << tree_[i] << ' ';
    }
  }

  T get(size_t qleft, size_t qright) {
    return get(0, 0, limit_, qleft, qright);
  }

  ~SegmentTree() {
    delete[] arr_;
    delete[] tree_;
  }
};

int main() {

  long long n = 0;
  std::cin >> n;
  long long* arr = new long long[n];
  for (size_t i = 0; i < n; ++i) {
    std::cin >> arr[i];
  }
  SegmentTree<long long> st(arr, n);
  long long left = 0;
  long long right = 0;
  long long a = 0;
  std::cin >> a;
  for (long long i = 0; i < a; i++) {
    std::cin >> left >> right;
    std::cout << st.get(left - 1, right) << '\n';
  }
  return 0;

}