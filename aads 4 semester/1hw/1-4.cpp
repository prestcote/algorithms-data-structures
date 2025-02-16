#include <iostream>
#include <algorithm>
#include <cstdint>

template <typename T>

class SegmentTree {
public:

  SegmentTree(const T* arr, size_t size) {
    arr_ = new T[size];
    size_ = size;
    for (size_t i = 0; i < size; i++) {
      arr_[i] = arr[i];
    }
    //std::cout << "hello?? ";
    tree_ = new std::pair<T, T>[4 * size_];
    while (limit_ < size) {
      limit_ <<= 1;
    }
    //std::cout << "hello?? ";
    build(0, 0, limit_);
  }

  void set(size_t index, T value) {
    set(0, 0, limit_, index, value);
  }

  std::pair<T, T> get(size_t left, size_t right) {
    return get(0, 0, limit_, left, right);
  }

  ~SegmentTree() {
    delete[] arr_;
    delete[] tree_;
  }

private:
  T* arr_;
  std::pair<T, T>* tree_;
  size_t size_ = 0;
  size_t limit_ = 1;

  void build(size_t v, size_t left, size_t right) {
    if (left + 1 == right && left < size_) {
      tree_[v] = { arr_[left], arr_[left] };

    }
    else if (left + 1 == right) {
      tree_[v] = { INT16_MAX, INT16_MIN };
    }
    else {
      size_t mid = (left + right) / 2;
      build(2 * v + 1, left, mid);
      build(2 * v + 2, mid, right);
      tree_[v].first = std::min(tree_[2 * v + 1].first, tree_[2 * v + 2].first);
      tree_[v].second = std::max(tree_[2 * v + 1].second, tree_[2 * v + 2].second);
      
    }
  }

  std::pair<T, T> get(size_t v, size_t left, size_t right, size_t qleft, size_t qright) {
    if (qleft <= left && qright >= right) {
      return tree_[v];
    }
    else if (qleft >= right || qright <= left) {
      return { INT16_MAX, INT16_MIN };
    }
    else {
      size_t mid = (left + right) / 2;
      T min_ = std::min(get(2 * v + 1, left, mid, qleft, qright).first, get(2 * v + 2, mid, right, qleft, qright).first);
      T max_ = std::max(get(2 * v + 1, left, mid, qleft, qright).second, get(2 * v + 2, mid, right, qleft, qright).second);
      return { min_, max_ };
    }
  }

  void set(size_t v, size_t left, size_t right, size_t index, size_t value) {
    if (left + 1 == right && left < size_) {
      arr_[left] = value;
      tree_[v] = { value, value };
    }
    else if (left + 1 == right) {
      return;
    }
    else {
      size_t mid = (left + right) / 2;
      if (index < mid) {
        set(2 * v + 1, left, mid, index, value);
      }
      else {
        set(2 * v + 2, mid, right, index, value);
      }
      T min_ = std::min(tree_[2 * v + 1].first, tree_[2 * v + 2].first);
      T max_ = std::max(tree_[2 * v + 1].second, tree_[2 * v + 2].second);
      tree_[v] = { min_, max_ };
    }
  }
};

int main() {
  int64_t k = 0;
  std::cin >> k;
  int64_t* arr = new int64_t[100001];
  for (int64_t i = 1; i < 100001; i++) {
    arr[i-1] = (i * i) % 12345 + (i * i * i) % 23456;
  }
  //std::cout << "in progress";
  SegmentTree<int64_t> st(arr, 100001);
  //std::cout << "done";
  //stmax.print();
  int64_t one = 0;
  int64_t two = 0;
  for (int64_t i = 0; i < k; i++) {
    std::cin >> one >> two;
    if (one > 0) {
      std::pair<int64_t, int64_t> ans = st.get(one - 1, two);
      std::cout << ans.second - ans.first << ' ';
    }
    if (one < 0) {
      st.set(-one-1, two);
    }
  }
  return 0;
}