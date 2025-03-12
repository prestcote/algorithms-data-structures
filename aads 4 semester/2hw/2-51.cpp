#include <iostream>
#include <functional>

template<typename T, T def, typename F>
struct SegmentTree {

  struct Node {
    F func_;
    T value_ = def;
    T mod_inc = 0;
    Node* left_ = nullptr;
    Node* right_ = nullptr;
    int begin_ = 0;
    int end_ = 0;
    explicit Node() = default;
    Node(int begin, int end, F func);
    T Get(int qbegin, int qend);
    void Build(Node* node);
    void Set(int index, T value);
    ~Node();
  } *root_ = nullptr;

  SegmentTree(int begin, int end, F func);

  void Set(int index, T value);

  T Get(int qbegin, int qend);

  ~SegmentTree();

};

template<typename T, T def, typename F>
SegmentTree<T, def, F>::Node::Node(int begin, int end, F func) :
  begin_(begin), end_(end), func_(func) { // HERE !!!!!!!!!!!!!!!
}

template<typename T, T def, typename F>
void SegmentTree<T, def, F>::Node::Build(Node* node) {
  if (node->begin_ + 1 == node->end_) {
    return;
  }
  int mid = (node->begin_ + node->end_) / 2;
  node->left_ = new Node(node->begin_, mid, node->func_);
  node->right_ = new Node(mid, node->end_, node->func_);
}

template<typename T, T def, typename F>
SegmentTree<T, def, F>::Node::~Node() {
  delete left_;
  delete right_;
}

template<typename T, T def, typename F>
SegmentTree<T, def, F>::SegmentTree(int begin, int end, F func) {
  root_ = new Node(begin, end, func);
}

template<typename T, T def, typename F>
SegmentTree<T, def, F>::~SegmentTree() {
  delete root_;
}

template<typename T, T def, typename F>
void SegmentTree<T, def, F>::Set(int index, T value) {
  root_->Set(index, value);
}

template<typename T, T def, typename F>
void SegmentTree<T, def, F>::Node::Set(int left, int right, T value) { // HERE !!!!!!!!!!!1
  if (left_ == nullptr) Build(this);
  if (begin_ + 1 == end_ || (left <= begin && right >= end) {
    mod_inc += value;
    return;
  }
  if (index < left_->end_) {
    left_->Set(index, value);
  }
  else {
    right_->Set(index, value);
  }
  value_ = func_(left_->value_, right_->value_);
}

template<typename T, T def, typename F>
T SegmentTree<T, def, F>::Get(int qbegin, int qend) {
  root_->Get(qbegin, qend);
}

template<typename T, T def, typename F>
T SegmentTree<T, def, F>::Node::Get(int qbegin, int qend) {
  if (left_ == nullptr) Build(this);
  if (qbegin <= begin_ && end_ <= qend) {
    return value_ + mod_inc;
  }
  if (qend <= begin_ || end_ <= qbegin) {
    return def;
  }
  return func_(left_->Get(qbegin, qend), right_->Get(qbegin, qend)) + mod_inc;
}

int summ(int a, int b) {
  return std::max(a, b);
}

int main() {
  SegmentTree<int, 0, std::function<int(int, int)> > sg(-10000000, 1000000, summ);
  for (int i = -10; i < 11; ++i) {
    sg.Set(i, i);
  }
  std::cout << sg.Get(-1, 5);
  return 0;
}
