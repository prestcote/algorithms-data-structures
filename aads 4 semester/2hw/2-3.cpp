#include <iostream>
#include <algorithm>

template <typename T>
class SegmentTree {
private:
  T* tree_;
  size_t size = 0;
  T* mod_;

  void push(size_t v, size_t left, size_t right) {
    if (mod_[v] != -1) {
      mod_[v * 2] = mod_[v];
      mod_[v * 2 + 1] = mod_[v];
      size_t mid = (left + right) / 2;
      tree_[v * 2] = (mid - left + 1) * mod_[v];
      tree_[v * 2 + 1] = (right - mid) * mod_[v];
      mod_[v] = -1;
    }
  }

  T get(size_t qleft, size_t qright, size_t v, size_t left, size_t right) {
    if (qleft <= left && right <= qright) {
      return tree_[v];
    }
    else if (qright < left || right < qleft) {
      return 0;
    }
    else {
      push(v, left, right);
      size_t mid = (left + right) / 2;
      return get(qleft, qright, 2 * v, left, mid) + get(qleft, qright, 2 * v + 1, mid + 1, right);
    }
  }

  void set(size_t qleft, size_t qright, T value, size_t v, size_t left, size_t right) {
    if (qleft <= left && right <= qright) {
      tree_[v] = value * (right - left + 1);
      mod_[v] = value;
      return;
    }
    if (qright < left || right < qleft) {
      return;
    }
    push(v, left, right);
    size_t mid = (left + right) / 2;
    set(qleft, qright, value, 2 * v, left, mid);
    set(qleft, qright, value, 2 * v + 1, mid + 1, right);
    tree_[v] = tree_[2 * v] + tree_[2 * v + 1];
  }

public:
  SegmentTree(size_t n) {
    size = n;
    mod_ = new T[4 * size];
    tree_ = new T[4 * size];
    for (size_t i = 0; i < 4 * size; i++) {
      tree_[i] = 0;
      mod_[i] = -1;
    }
  }

  void print() {
    for (size_t i = 0; i < 4 * size; ++i) {
      std::cout << tree_[i] << ' ';
    }
  }

  void set(size_t qleft, size_t qright, T value) {
    set(qleft, qright, value, 1, 0, size-1);
  }

  T get(size_t qleft, size_t qright) {
    return get(qleft, qright, 1, 0, size-1);
  }

};

int main() {
  size_t n = 0;
  long long k = 0;
  std::cin >> n >> k;
  SegmentTree<long long> st(n);
  char p;
  long long l = 0;
  long long r = 0;
  long long x = 0;
  for (long long i = 0; i < k; i++) {
    std::cin >> p >> l >> r;
    if (p == 'A') {
      std::cin >> x;
      st.set(l - 1, r - 1, x);
    }
    else {
      std::cout << st.get(l - 1, r - 1) << '\n';
    }
  }
}