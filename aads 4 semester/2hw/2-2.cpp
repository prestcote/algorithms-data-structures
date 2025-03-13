#include <iostream>
#include <functional>

template<typename T>
struct SegmentTree {

  struct Node {
    T value_ = 0;
    Node* left_ = nullptr;
    Node* right_ = nullptr;
    int begin_ = 0;
    int end_ = 0;
    explicit Node() = default;
    Node(int begin, int end);
    T Get(int qbegin, int qend);
    void Build(Node* node);
    void Set(int index, T value);
    ~Node();
  } *root_ = nullptr;

  SegmentTree(int begin, int end);

  void Set(int index, T value);

  T Get(int qbegin, int qend);

  ~SegmentTree();

};

template<typename T>
SegmentTree<T>::Node::Node(int begin, int end) :
  begin_(begin), end_(end) {
}

template<typename T>
void SegmentTree<T>::Node::Build(Node* node) {
  if (node->begin_ + 1 == node->end_) {
    return;
  }
  int mid = (node->begin_ + node->end_) / 2;
  node->left_ = new Node(node->begin_, mid);
  node->right_ = new Node(mid, node->end_);
}

template<typename T>
SegmentTree<T>::Node::~Node() {
  delete left_;
  delete right_;
}

template<typename T>
SegmentTree<T>::SegmentTree(int begin, int end) {
  root_ = new Node(begin, end);
}

template<typename T>
SegmentTree<T>::~SegmentTree() {
  delete root_;
}

template<typename T>
void SegmentTree<T>::Set(int index, T value) {
  root_->Set(index, value);
}

template<typename T>
void SegmentTree<T>::Node::Set(int index, T value) {
  if (left_ == nullptr) Build(this);
  if (begin_ + 1 == end_) {
    value_ = value;
    return;
  }
  if (index < left_->end_) {
    left_->Set(index, value);
  }
  else {
    right_->Set(index, value);
  }
  value_ = summ(left_->value_, right_->value_);
}

template<typename T>
T SegmentTree<T>::Get(int qbegin, int qend) {
  return root_->Get(qbegin, qend);
}

template<typename T>
T SegmentTree<T>::Node::Get(int qbegin, int qend) {
  if (left_ == nullptr) Build(this);
  if (qbegin <= begin_ && end_ <= qend) {
    return value_;
  }
  if (qend <= begin_ || end_ <= qbegin) {
    return 0;
  }
  return summ(left_->Get(qbegin, qend), right_->Get(qbegin, qend));
}

int summ(int a, int b) {
  return a + b;
}

int main() {
  SegmentTree<int> sg(-10000000, 1000000);
  for (int i = -10; i < 11; ++i) {
    sg.Set(i, i);
  }
  std::cout << sg.Get(-1, 5);
  return 0;
}
