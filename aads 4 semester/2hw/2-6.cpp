#include <iostream>

template <typename T>
class SegmentTree {
private:
  size_t limit_ = 1;
  size_t size_ = 0;
  T* arr_;
  T* tree_;

  void build(size_t v, size_t left, size_t right) {
    if (left + 1 == right && left < size_) {
      tree_[v] = arr_[left];
    }
    else if (left + 1 == right) {
      tree_[v] = -1;
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
      tree_[v] = value;
      arr_[index] = value;
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

  T get(size_t v, size_t left, size_t right, T w, size_t i) {
    if (right <= i || tree_[v] < w) {
      return -1;
    }
    else if (left + 1 == right) {
      //arr_[left] += value;
      //tree_[v] += value;
      return left;
    }
    else {
      size_t mid = (left + right) / 2;
      T l_tree = get(2 * v + 1, left, mid, w, i);
      if (l_tree != -1) {//&& tree_[t1] + value <= w) {
        //T l_tree = get(2 * v + 1, left, mid, w, i);
        return l_tree;
      }
      else {// if (tree_[t2] + value <= w) {
        T r_tree = get(2 * v + 2, mid, right, w, i);
        return r_tree;
      }

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

  ~SegmentTree() {
    delete[] tree_;
    delete[] arr_;
  }

  T get(size_t i, T w) {
    return get(0, 0, limit_, w, i);
  }

  void set(size_t index, T value) {
    set(0, 0, limit_, index, value);
  }

  void print() {
    std::cout << size_ << '\n';
    for (int i = 0; i < size_ * 4; i++) {
      std::cout << tree_[i] << ' ';
    }

  }

};

int main() {
  long long n = 0;
  long long m = 0;
  std::cin >> n >> m;
  long long* arr = new long long[n];
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }
  SegmentTree<long long> st(arr, n);
  //st.print();
  long long xi = 0;
  long long x = 0;
  int c = 0;
  for (int i = 0; i < m; i++) {
    std::cin >> c >> xi >> x;
    if (c == 0) {
      st.set(xi - 1, x);
    }
    else {
      long long ans = st.get(xi - 1, x);
      if (ans == -1) {
        std::cout << ans << '\n';
      }
      else {
        std::cout << ans + 1 << '\n';
      }
      
    }
  }
  return 0;
}