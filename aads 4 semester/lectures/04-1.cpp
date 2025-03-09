//2791 informatics

#include <iostream>
#include <random>
#include <ctime>

std::mt19937_64 rd(time(0));

template <typename T>
class Trie {
private:
  struct Node {
    Node* left = nullptr;
    Node* right = nullptr;
    T value;
    int size = 1;
    size_t prior = rd();
    Node(T value) :
      value(value) {};
    ~Node() {
      delete[] left;
      delete[] right;
    }
  } *root = nullptr;
  int Size(Node* node) {
    return node == nullptr ? 0 : node->size;
  }
  void Update(Node* node) {
    if (node == nullptr) {
      return;
    }
    node->size == Size(Node->left) + Size(node->right) + 1;
  }

  Node* merge(Node* less, Node* more) {
    if (less == nullptr) return more;
    if (more == nullptr) return less;
    if (less->prior > more->prior) {
      less->right = merge(less->right, more);
      Update(less);
      return less;
    }
    more->left = merge(less, more->left);
    Update(more);
    return more;
  }

  std::pair<Node, Node> Split(Node* node, int count) {
    if (node == nullptr) {
      return { nullptr, nullptr };
    }
    if (Size(node->left) >= count) {
      auto cur = Split(node->left, count);
      node->left = cur.second;
      Update(node);
      return({ cur.first, node });
    }
    auto cur = Split(node->right, count - Size(node->left) - 1);
    node->right = cur.first;
    Update(node);
    return { node, cur.second };
  }

  void Print(Node* node) {
    if (node == nullptr) return;
    Print(node->left);
    std::cout << node->value << ' ';
    Print(node->right);
  }

public:
  explicit Trie() = default;
  Trie(Trie&& t) { };
  ~Trie() {
    delete[] root;
  }

  void Insert(int index, T value) {
    auto cur = Split(index);
    root = Merge(cur.first, new Node(value));
    root = Merge(root, cur.second);
  }

  void Print() {
    Print(root);
  }

  void MoveToBegin(int left, int right) {
    auto cur1 = Split(root, left);
    auto cur2 = Split(cur1.second, right - left + 1);
    root = Merge(cur2.first, cur1.first);
    root = Merge(root, cur2.second);
  }
 
};

int main() {

  Trie<int>trie;
  int n = 0;
  int m = 0;
  std::cin >> n >> m;
  for (int i = 0; i < n; i++) {
    trie.Insert(i, i + 1);
  }
  while (m--) {
    int l = 0;
    int r = 0;
    std::cin >> l >> r;
    --l;
    --r;
    trie.MoveToBegin(l, r);
  }
  trie.Print();
  return 0;

}

