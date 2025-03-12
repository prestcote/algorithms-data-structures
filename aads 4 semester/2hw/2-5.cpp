#include <iostream>
#include <algorithm>

template <typename T>
class SegmentTree {
private:
  T* arr_;
  T* tree_;
  size_t size = 0;
  T* mod_set;
  T* mod_inc;

  void build_tree(int v, int tl, int tr) {
    if (tl == tr) {
      tree_[v] = arr_[tl];
      mod_inc[v] = 0;
      mod_set[v] = -1;
    }
    else {
      int tm = (tl + tr) / 2;
      build_tree(v * 2 + 1, tl, tm);
      build_tree(v * 2 + 2, tm + 1, tr);
      tree_[v] = tree_[v * 2 + 1] + tree_[v * 2 + 2];
      mod_inc[v] = 0;
      mod_set[v] = -1;
    }
  }


  void push(size_t v, size_t left, size_t right) {

    if (mod_set[v] != -1) {
      tree_[v] = mod_set[v] * (right - left + 1);
      if (left != right) {
        mod_set[v * 2 + 1] = mod_set[v];
        mod_set[v * 2 + 2] = mod_set[v];
        mod_inc[v * 2 + 1] = 0;
        mod_inc[v * 2 + 2] = 0;
      }
      //size_t mid = (left + right) / 2;
      //tree_[v * 2] = (mid - left + 1) * mod_set[v];
      //tree_[v * 2 + 1] = (right - mid) * mod_set[v];
      mod_set[v] = -1;
      //mod_inc[v] = 0;
    }

    if (mod_inc[v] != 0) {
      tree_[v] += mod_inc[v] *(right - left + 1);
      if (left != right) {
        mod_inc[v * 2 + 1] += mod_inc[v];
        mod_inc[v * 2 + 2] += mod_inc[v];
      }
      mod_inc[v] = 0;
    }
  }

  T get(size_t qleft, size_t qright, size_t v, size_t left, size_t right) {
    push(v, left, right);
    if (qleft <= left && right <= qright) {
      return tree_[v];
    }
    else if (qright < left || right < qleft) {
      return 0;
    }
    else {
      //push(v, left, right);
      size_t mid = (left + right) / 2;
      return get(qleft, qright, 2 * v + 1, left, mid) + get(qleft, qright, 2 * v + 2, mid + 1, right);
    }
  }

  void set(size_t qleft, size_t qright, T value, size_t v, size_t left, size_t right) {
    push(v, left, right);
    if (qleft <= left && right <= qright) {
      //tree_[v] = value * (right - left + 1);
      mod_set[v] = value;
      mod_inc[v] = 0;
      push(v, left, right);
      return;
    }
    if (qright < left || right < qleft) {
      return;
    }
    size_t mid = (left + right) / 2;
    set(qleft, qright, value, 2 * v + 1, left, mid);
    set(qleft, qright, value, 2 * v + 2, mid + 1, right);
    tree_[v] = tree_[2 * v + 1] + tree_[2 * v + 2];
  }

  void increase(size_t qleft, size_t qright, T value, size_t v, size_t left, size_t right) {
    push(v, left, right);
    if (qleft <= left && right <= qright) {
      mod_inc[v] += value;
      push(v, left, right);
      return;

    }
    if (qright < left || right < qleft) {
      return;
    }
    //push(v, left, right);
    size_t mid = (left + right) / 2;
    increase(qleft, qright, value, 2 * v + 1, left, mid);
    increase(qleft, qright, value, 2 * v + 2, mid + 1, right);
    tree_[v] = tree_[2 * v + 1] + tree_[2 * v + 2];
  }

public:
  SegmentTree(size_t n, const T* arr) {
    size = n;
    arr_ = new T[size];
    for (int i = 0; i < size; i++) {
      arr_[i] = arr[i];
    }
    mod_set = new T[4 * size];
    mod_inc = new T[4 * size];
    tree_ = new T[4 * size];
    for (size_t i = 0; i < 4 * size; i++) {
      mod_set[i] = -1;
      mod_inc[i] = 0;
    }
    build_tree(0, 0, n - 1);
  }

  ~SegmentTree() {
    delete[] arr_;
    delete[] tree_;
    delete[] mod_inc;
    delete[] mod_set;
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

  void increase(size_t qleft, size_t qright, T value) {
    increase(qleft, qright, value, 0, 0, size - 1);
  }

};

int main() {
  size_t n = 0;
  long long k = 0;
  std::cin >> n >> k;
  long long* arr = new long long[n];
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }
  SegmentTree<long long> st(n, arr);
  int c;
  long long l = 0;
  long long r = 0;
  long long x = 0;
  for (long long i = 0; i < k; i++) {
    std::cin >> c;
    if (c == 1) {
      std::cin >> l >> r >> x;
      st.increase(l-1, r-1, x);
    }
    else if (c == 2) {
      std::cin >> l >> r >> x;
      st.set(l - 1, r - 1, x);
    }
    else {
      std::cin >> l >> r;
      std::cout << st.get(l-1, r-1) << '\n';
    }
  }
}