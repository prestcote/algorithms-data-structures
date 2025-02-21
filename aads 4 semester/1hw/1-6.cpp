#include <iostream>

template <typename T>
class SegmentTree {
private:
  size_t limit_ = 1;
  size_t size_ = 0;
  T* tree_;

  T set(size_t v, size_t left, size_t right, T value, T w) {
    if (left + 1 == right && left < size_ && tree_[v] + value <= w) {
      //arr_[left] += value;
      tree_[v] += value;
      return v + 1; 
    }
    else if (left + 1 == right && (left >= size_ || tree_[v] > w)) {
      return -1;
    }
    else {
      size_t mid = (left + right) / 2;
      if (tree_[2*v+1] + value <= w) {
        set(2 * v + 1, left, mid, value, w);
        tree_[v] = tree_[2 * v + 1];
      }
      else if (tree_[2*v+2] + value <= w) {
        set(2 * v + 2, mid, right, value, w);
        tree_[v] = tree_[2 * v + 2];
      }
      else {
        return -1;
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

  T set(size_t value, T w) {
    return set(0, 0, limit_, value, w);
  }

};

int main() {
  long long h = 0;
  long long w = 0;
  long long n = 0;
  SegmentTree<long long> st(std::min(h, n));
  std::cin >> h >> w >> n;
  long long v = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> v;
    std::cout << st.set(v, w) << '\n';
  }
}