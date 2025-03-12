#include <iostream>
#include <algorithm>

template <typename T>
class SegmentTree {
private:
  T* arr_;
  T* tree_;
  size_t size = 0;
  T* mod_;

  void build(size_t v, size_t left, size_t right) {
    if (left == right) {
      tree_[v] = arr_[left];
      mod_[v] = 0;
    }
    else {
      size_t mid = (left + right) / 2;
      build(v * 2 + 1, left, mid);
      build(v * 2 + 2, mid + 1, right);
      tree_[v] = std::max(tree_[v * 2+1], tree_[v * 2 + 2]);
      mod_[v] = 0;
    }
  }


  void push(size_t v, size_t left, size_t right) {
    if (mod_[v] != 0) {
      tree_[v] += mod_[v];
      if (left != right) {
        mod_[v * 2 + 1] += mod_[v];
        mod_[v * 2 + 2] += mod_[v];
      }
      mod_[v] = 0;
    }
  }

  T get(size_t qleft, size_t qright, size_t v, size_t left, size_t right) {
    push(v, left, right);
    if (qleft <= left && right <= qright) {
      return tree_[v];
    }
    else if (qright < left || right < qleft) {
      return -1;
    }
    else {
      //push(v, left, right);
      size_t mid = (left + right) / 2;
      return std::max(get(qleft, qright, 2 * v + 1, left, mid), get(qleft, qright, 2 * v + 2, mid + 1, right));
    }
  }

  void set(size_t qleft, size_t qright, T value, size_t v, size_t left, size_t right) {
    push(v, left, right);
    if (qleft <= left && right <= qright) {
      mod_[v] += value;
      push(v, left, right);
      return;
      
    }
    if (qright < left || right < qleft) {
      return;
    }
    //push(v, left, right);
    size_t mid = (left + right) / 2;
    set(qleft, qright, value, 2 * v + 1, left, mid);
    set(qleft, qright, value, 2 * v + 2, mid + 1, right);
    tree_[v] = std::max(tree_[2 * v + 1], tree_[2 * v + 2]);
  }

public:
  SegmentTree(size_t n, const T* arr) {
    size = n;
    //std::cout << size << "\n\n";
    arr_ = new T[size];
    mod_ = new T[4 * size];
    tree_ = new T[4 * size];
    for (size_t i = 0; i < size; i++) {
      arr_[i] = arr[i];
    }
    for (size_t i = 0; i < 4 * size; i++) {
      mod_[i] = 0;
      tree_[i] = -1;
    }
    build(0, 0, n - 1);
  }

  ~SegmentTree() {
    delete[] arr_;
    delete[] tree_;
    delete[] mod_;
  }

  void print() {
    for (size_t i = 0; i < 4 * size; ++i) {
      std::cout << tree_[i] << ' ';
    }
  }

  void set(size_t qleft, size_t qright, T value) {
    set(qleft, qright, value, 0, 0, size - 1);
  }

  T get(size_t qleft, size_t qright) {
    return get(qleft, qright, 0, 0, size - 1);
  }

};

int main() {
  size_t n = 0;
  long long m = 0;
  std::cin >> n;
  long long* arr = new long long[n];
  for (long long i = 0; i < n; i++) {
    std::cin >> arr[i];
  }
  //std::cout << '\n';
  //std::cout << '\n';
  std::cin >> m;
  SegmentTree<long long> st(n, arr);
  char c;
  long long l = 0;
  long long r = 0;
  long long x = 0;
  for (long long i = 0; i < m; i++) {
    std::cin >> c;
    if (c == 'a') {
      std::cin >> l >> r >> x;
      st.set(l-1, r-1, x);
    }
    else {
      std::cin >> l >> r;
      std::cout << st.get(l-1, r-1) << '\n';
    }
  }
}