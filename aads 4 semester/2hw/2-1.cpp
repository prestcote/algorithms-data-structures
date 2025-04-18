#include <iostream>
#include <algorithm>

template <typename T>
class SegmentTree {
private:
  //T* arr_;
  T* tree_;
  size_t size = 0;
  T* mod_;
  /*
  void build(size_t v, size_t left, size_t right) {
    if (left == right) {
      tree_[v] = arr_[left];
      mod_[v] = 0;
    }
    else {
      size_t mid = (left + right) / 2;
      build(v * 2 + 1, left, mid);
      build(v * 2 + 2, mid + 1, right);
      tree_[v] = std::max(tree_[v * 2 + 1], tree_[v * 2 + 2]);
      mod_[v] = 0;
    }
  }
  */

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
      return 0;
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
  SegmentTree(size_t n) {
    size = n;
    //std::cout << size << "\n\n";
    //arr_ = new T[size];
    mod_ = new T[4 * size];
    tree_ = new T[4 * size];
    /*
    for (size_t i = 0; i < size; i++) {
      arr_[i] = arr[i];
    }*/
    for (size_t i = 0; i < 4 * size; i++) {
      mod_[i] = 0;
      tree_[i] = 0;
    }
    //build(0, 0, n - 1);
  }

  ~SegmentTree() {
    //delete[] arr_;
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
  long long k = 0;
  std::cin >> n >> k >> m;
  long long* arr = new long long[n];
  long long x = 0;
  long long y = 0;
  SegmentTree<long long>st(n);
  for (long long i = 0; i < m; i++) {
    std::cin >> x >> y;
    long long s = st.get(x, y-1);
    if (s < k) {
      st.set(x, y-1, 1);
      //std::cout << '\n';
      //st.print();
      //std::cout << '\n';
      std::cout << 1 << '\n'; // << ' ' << s << '\n';
    }
    else {
      std::cout << 0 << '\n';
    }
  }

}