#include <iostream>
#include <ctime>
#include <random>

std::mt19937_64 rd(time(0));

template <typename T>
class Trie {
private:
  struct Node {
    Node* left = nullptr;
    Node* right = nullptr;
    T value = 0;
    T prior = rd();
    int size = 1;
    Node(T value) : value(value) {}
    ~Node() {
      delete left;
      delete right;
    }
  } *root = nullptr;

  int Size(Node* node) {
    if (node == nullptr) {
      return 0;
    }
    return node->size;
  }

  void Update(Node* node) {
    if (node == nullptr) return;
    node->size = Size(node->left) + Size(node->right) + 1;
  }

  Node* Merge(Node* less, Node* more) {
    if (less == nullptr) return more;
    if (more == nullptr) return less;
    if (less->prior > more->prior) {
      less->right = Merge(less->right, more);
      Update(less);
      return less;
    }
    more->left = Merge(less, more->left);
    Update(more);
    return more;
  }

  std::pair<Node*, Node*> Split(Node* node, T count) {
    if (node == nullptr) return { nullptr, nullptr };
    if (node->value >= count) {
      auto cur = Split(node->left, count);
      node->left = cur.second;
      Update(node);
      return { cur.first, node };
    }
    auto cur = Split(node->right, count);
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
  Trie() = default;
  ~Trie() {
    delete root;
  }

  bool Find(T key) {
    Node* temp = root;
    while (temp) {
      if (temp->value == key) return true;
      if (temp->value > key) {
        temp = temp->left;
      }
      else {
        temp = temp->right;
      }
    }
    return false;
  }

  void Insert(T value) {
    if (Find(value)) return;
    auto q = Split(root, value);
    root = Merge(Merge(q.first, new Node(value)), q.second);
  }
  
  int Min(T value) {
    auto q = Split(root, value);
    if (q.second == nullptr) {
      root = Merge(q.first, q.second);
      return -1;
    }
    Node* node = q.second;
    while (node->left) {
      node = node->left;
    }
    T ans = node->value;
    root = Merge(q.first, q.second);
    return ans;
  }


};

int main() {
  int n = 0;
  std::cin >> n;
  Trie<int> tree;
  int pr = 0;
  char c;
  int one = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> c;
    if (c == '+') {
      std::cin >> one;
      //one = (one + pr + 1000000000) % 1000000000;
      one = (one + pr) % 1000000000;
      pr = 0;
      tree.Insert(one);
    }
    else if (c == '?') {
      std::cin >> one;
      pr = tree.Min(one);
      std::cout << pr << '\n';
    }
  }
  return 0;
}

