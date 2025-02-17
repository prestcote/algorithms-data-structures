#include <iostream>
#include <algorithm>
#include <cstdint>
/*
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
*/

template <typename T>
class SegmentTreeMax {
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
      tree_[v] = -1000000000;
    }
    else {
      size_t mid = (left + right) / 2;
      build(2 * v + 1, left, mid);
      build(2 * v + 2, mid, right);
      tree_[v] = std::max(tree_[2 * v + 1], tree_[2 * v + 2]);
    }
  }
  void set(size_t v, size_t left, size_t right, size_t index, T value) {
    if (left + 1 == right && left < size_) {
      arr_[left] = value;
      tree_[v] = value;
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
      tree_[v] = std::max(tree_[2 * v + 1], tree_[2 * v + 2]);
    }
  }
  T get(size_t v, size_t left, size_t right, size_t qleft, size_t qright) {
    if (qleft <= left && right <= qright) {
      return tree_[v];
    }
    else if (qright <= left || right <= qleft) {
      return -10000000000;
    }
    else {
      size_t mid = (left + right) / 2;
      return std::max(get(2 * v + 1, left, mid, qleft, qright), get(2 * v + 2, mid, right, qleft, qright));
    }
  }
public:
  SegmentTreeMax(const T* arr, size_t size) {
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
  void set(size_t index, T value) {
    set(0, 0, limit_, index, value);
  }
  ~SegmentTreeMax() {
    delete[] arr_;
    delete[] tree_;
  }
};

template <typename T>
class SegmentTreeMin {
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
      tree_[v] = 10000000000;
    }
    else {
      size_t mid = (left + right) / 2;
      build(2 * v + 1, left, mid);
      build(2 * v + 2, mid, right);
      tree_[v] = std::min(tree_[2 * v + 1], tree_[2 * v + 2]);
    }
  }
  void set(size_t v, size_t left, size_t right, size_t index, T value) {
    if (left + 1 == right && left < size_) {
      arr_[left] = value;
      tree_[v] = value;
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
      tree_[v] = std::min(tree_[2 * v + 1], tree_[2 * v + 2]);
    }
  }
  T get(size_t v, size_t left, size_t right, size_t qleft, size_t qright) {
    if (qleft <= left && right <= qright) {
      return tree_[v];
    }
    else if (qright <= left || right <= qleft) {
      return 10000000000;
    }
    else {
      size_t mid = (left + right) / 2;
      return std::min(get(2 * v + 1, left, mid, qleft, qright), get(2 * v + 2, mid, right, qleft, qright));
    }
  }

public:
  SegmentTreeMin(const T* arr, size_t size) {
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

  void set(size_t index, T value) {
    set(0, 0, limit_, index, value);
  }

  ~SegmentTreeMin() {
    delete[] arr_;
    delete[] tree_;
  }
};


int main() {
  long long k = 0;
  std::cin >> k;
  long long* arr = new long long[100001];
  for (long long i = 1; i < 100001; ++i) {
    arr[i - 1] = (i * i) % 12345 + (i * i * i) % 23456;
  }
  //std::cout << "in progress";
  SegmentTreeMax<long long> stmax(arr, 100001);
  SegmentTreeMin<long long> stmin(arr, 100001);
  //std::cout << "done";
  stmax.print();
  long long one = 0;
  long long two = 0;
  for (long long i = 0; i < k; i++) {
    std::cin >> one >> two;
    if (one > 0) {
      //std::pair<long long, long long> ans = st.get(one - 1, two);
      std::cout << stmax.get(one - 1, two) - stmin.get(one - 1, two) << ' ';
    }
    if (one < 0) {
      stmax.set(-one - 1, two);
      stmin.set(-one - 1, two);
    }
  }
  return 0;
}