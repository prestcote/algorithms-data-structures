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
    T sum = 0;
    long long size = 1;
    Node(T value) : value(value), sum(value) {}
    ~Node() {
      delete left;
      delete right;
    }
  } *root = nullptr;

  long long Size(Node* node) {
    if (node == nullptr) {
      return 0;
    }
    return node->size;
  }

  T Sum(Node* node) {
    if (node == nullptr) {
      return 0;
    }
    return node->sum;
  }

  void Update(Node* node) {
    if (node == nullptr) return;
    node->size = Size(node->left) + Size(node->right) + 1;
    node->sum = Sum(node->left) + node->value + Sum(node->right);
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

  T Sum(long long l, long long r) {
    auto q = Split(root, l);
    auto q1 = Split(q.second, r + 1);
    T ans = 0;
    if (q1.first != nullptr) {
      ans = q1.first->sum;
    }
    root = Merge(Merge(q.first, q1.first), q1.second);
    return ans;
  }


};

int main() {
  long long n = 0;
  std::cin >> n;
  Trie<long long> tree;
  long long pr = 0;
  char c;
  long long one = 0;
  long long two = 0;
  for (long long i = 0; i < n; i++) {
    std::cin >> c;
    if (c == '+') {
      std::cin >> one;
      if (i > 0 && c == '+') {  // Исправлено
        one = (one + pr) % 1000000000;
      }
      tree.Insert(one);
      pr = 0;
    }
    else if (c == '?') {
      std::cin >> one >> two;
      pr = tree.Sum(one, two);
      std::cout << pr << '\n';
    }
  }
  return 0;
}

