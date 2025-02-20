#include <iostream>
/*
template <typename T, T def>
struct SegmentTree {
  struct Node {
    T value_ = def;
    Node* left = nullptr;
    Node* right = nullptr;
    int begin_ = 0;
    int end_ = 0;
    explicit Node() = default;
    Node(int begin, int end);
    ~Node();
    void Set(long long index, T value);
  } *root_ = nullptr;
  SegmentTree(int begin, int end);
  ~SegmentTree();

  void Set(long long index, T value);
};

template<typename T, T def>
SegmentTree<T, def>::Node::Node(int begin, int end) :
  begin_(begin), end_(end) {
  if (begin_ + 1 == end_) {
    return;
  }
  long long mid = (begin + end) / 2;
  left_ = new Node(begin_, mid);
  right_ = new Node(mid, end_);
};

template<typename T, T def>
SegmentTree<T, def>::Node::~Node() {
  delete left_;
  delete right_;
}

template <typename T, T def>
SegmentTree<T, def>::SegmentTree(int begin, int end) {
  root_ = new Node(begin, end);
}

template<typename T, T def>
SegmentTree<T, def>::~SegmentTree() {
  delete root_;
}

template<typename T, T def>
void SegmentTree<typename T, def>::Set(long long index, T value) {
  root_->Set(index, value);
}

template<typename T, T def>
void SegmentTree<T, def>::Node::Set(long long index, T value) {
  if (begin_ + 1 == end_) {
    VALUE_ - VALUE;
  }
  if (index < left_->end_) {
    left_->Set(index, value);
  }
  else {
    right_->Set(index, value);
  }
  value_ = 
}
*/
int main() {

  return 0;
}