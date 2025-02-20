#include <iostream>

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
      tree_[v] = tree_[2 * v + 1] + tree_[2 * v + 2];
    }
  }

  T get(size_t v, size_t left, size_t right, size_t qleft, size_t qright) {
    if (qleft <= left && qright >= right) {
      return tree_[v];
    }
    else if (qleft >= right || qright <= left) {
      return 0;
    }
    else {
      size_t mid = (left + right) / 2;
      return (get(2 * v + 1, left, mid, qleft, qright) + get(2 * v + 2, mid, right, qleft, qright));

    }
  }

public:
  SegmentTree(T* arr, size_t size) {
    size_ = size;
    for (int i = 0; i < size; i++) {
      arr_[i] = arr[i];
    }
    while (limit_ < size_) {
      limit_ <<= 1;
    }
    tree_ = new T[4 * size];
    build(0, 0, limit_);
  }

  T get(size_t left, size_t right) {
    return 0;
  }
};

int main() {

}