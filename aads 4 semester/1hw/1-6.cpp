#include <iostream>

template <typename T>
class SegmentTree {
private:
  size_t limit_ = 1;
  size_t size_ = 0;
  T* tree_;

  void set(size_t v, size_t left, size_t right, size_t index, T value) {
    if (left + 1 == right && left < size_) {
      tree_[v] += value;
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

  T get(size_t v, size_t left, size_t right, T value, T w) {
    if (left + 1 == right && left < size_ && tree_[v] + value <= w) {
      //arr_[left] += value;
      //tree_[v] += value;
      return left;
    }
    else if (left + 1 == right || (tree_[2*v+1] + value > w && tree_[2*v+2] + value > w)) {
      return -1;
    }
    else {
      size_t mid = (left + right) / 2;
      if (tree_[2*v+1] + value <= w) {//&& tree_[t1] + value <= w) {
        T l_tree = get(2 * v + 1, left, mid, value, w);
        return l_tree;
      }
      else {// if (tree_[t2] + value <= w) {
        T r_tree = get(2 * v + 2, mid, right, value, w);
        return r_tree;
      }
      
    }
  }

public:
  SegmentTree(size_t size) {
    tree_ = new T[4 * size];
    
    for (int i = 0; i < 4 * size; i++) {
      tree_[i] = 0;
    }
    size_ = size;
    while (limit_ < size) {
      limit_ <<= 1;
    }
  }

  ~SegmentTree() {
    delete[] tree_;
  }

  T get(size_t value, T w) {
    return get(0, 0, limit_, value, w);
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
  long long h = 0;
  long long w = 0;
  long long n = 0;
  std::cin >> h >> w >> n;
  SegmentTree<long long> st(std::min(h, n));
  //st.print();
  long long v = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> v;
    long long ans = st.get(v, w);
    if (ans != -1) {
      std::cout << ans + 1 << '\n';
    }
    else {
      std::cout << ans << '\n';
    }
    if (ans != -1) {
      st.set(ans, v);
    }
    //st.print();
    //std::cout << '\n';
  }
  return 0;
}