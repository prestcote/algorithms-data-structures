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
      tree_[v] = { arr_[left], 1 };

    }
    else if (left + 1 == right) {
      tree_[v] = { 0, -1 };
    }
    else {
      size_t mid = (left + right) / 2;
      build(2 * v + 1, left, mid);
      build(2 * v + 2, mid, right);

      if (tree_[2 * v + 1].first > tree_[2 * v + 2].first) {
        tree_[v] = tree_[2 * v + 1];
      }
      else if (tree_[2 * v + 1].first < tree_[2 * v + 2].first) {
        tree_[v] = tree_[2 * v + 2];
      }
      else {
        tree_[v] = tree_[2 * v + 1];
        tree_[v].second += tree_[2 * v + 2].second;
      }

    }
  }

  std::pair<T, T> get(size_t v, size_t left, size_t right, size_t qleft, size_t qright) {
    if (qleft <= left && qright >= right) {
      return tree_[v];
    }
    else if (qleft >= right || qright <= left) {
      return { 0, -1 };
    }
    else {
      size_t mid = (left + right) / 2;
      std::pair<T, T> one_ = get(2 * v + 1, left, mid, qleft, qright);
      std::pair<T, T> two_ = get(2 * v + 2, mid, right, qleft, qright);

      if (one_.first > two_.first) {
        return one_;
      }
      else if (one_.first < two_.first) {
        return two_;
      }
      else {
        one_.second += two_.second;
        return one_;
      }
    }
  }

  void set(size_t v, size_t left, size_t right, size_t index, size_t value) {
    if (left + 1 == right && left < size_) {
      arr_[left] = value;
      tree_[v] = { value, 1 };
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

      if (tree_[2 * v + 1].first > tree_[2 * v + 2].first) {
        tree_[v] = tree_[2 * v + 1];
      }
      else if (tree_[2 * v + 1].first < tree_[2 * v + 2].first) {
        tree_[v] = tree_[2 * v + 2];
      }
      else {
        tree_[v] = tree_[2 * v + 1];
        tree_[v].second += tree_[2 * v + 2].second;
      }
    }
  }
};

int main() {
  long long n = 0;
  std::cin >> n;
  long long* arr = new long long[n];
  for (size_t i = 0; i < n; i++) {
    std::cin >> arr[i];
  }
  SegmentTree<long long> st(arr, n);
  long long k = 0;
  std::cin >> k;
  long long left = 0;
  long long right = 0;

  for (long long i = 0; i < k; i++) {
    std::cin >> left >> right;
    std::pair<long long, long long> ans = st.get(left - 1, right);
    std::cout << ans.first << ' ' << ans.second << '\n';
  }
}