#include <iostream>
#include <random>
#include <ctime>
#include <string>

std::mt19937_64 rd(time(0));

class Tree {
private:
  struct Node {
    long long value = 0;
    long long sum = 0;
    uint64_t prior = rd();
    Node* left = nullptr;
    Node* right = nullptr;
    Node(long long value) : value(value), sum(value) {}
    long long size = 1;
    long long height = 1;
  } *root = nullptr;

  long long size(Node* node) {
    return node != nullptr ? node->size : 0;
  }

  long long height(Node* node) {
    return node != nullptr ? node->height : 0;
  }

  long long sum(Node* node) {
    if (node == nullptr) {
      return 0;
    }
    return node->sum;
  }

  void update(Node* node) {
    if (node != nullptr) {
      node->size = size(node->left) + size(node->right) + 1;
      node->height = std::max(height(node->left), height(node->right)) + 1;
      node->sum = sum(node->left) + node->value + sum(node->right);
    }
  }

  Node* merge(Node* less, Node* more) {
    if (less == nullptr) return more;
    if (more == nullptr) return less;
    if (less->prior > more->prior) {
      less->right = merge(less->right, more);
      update(less);
      return less;
    }
    more->left = merge(less, more->left);
    update(more);
    return more;
  }

  std::pair<Node*, Node*> split(Node* curr, long long key) {
    if (curr == nullptr) {
      return { nullptr, nullptr };
    }
    if (curr->value > key) {
      auto q = split(curr->left, key);
      curr->left = q.second;
      update(curr);
      return { q.first, curr };
    }
    auto q = split(curr->right, key);
    curr->right = q.first;
    update(curr);
    return { curr, q.second };
  }

  void print(Node* node) {
    if (node == nullptr) return;
    print(node->left);
    std::cout << node->value << ' ';
    print(node->right);
  }


public:

  void insert(long long value) {
    if (find(value)) return;
    auto q = split(root, value);
    root = merge(merge(q.first, new Node(value)), q.second);
  }

  Node* del(Node* node, long long value) {
    if (!node) return nullptr;
    if (node->value == value) {
      Node* ans = merge(node->left, node->right);
      delete node;
      return ans;
    }
    if (value < node->value) {
      node->left = del(node->left, value);

    }
    else {
      node->right = del(node->right, value);
    }
    update(node);
    return node;
  }

  void del(long long v) {
    root = del(root, v);
  }

  long long sum(long long l, long long r) {
    auto q = split(root, l - 1);
    auto q1 = split(q.second, r);
    long long ans = 0;
    if (q1.first != nullptr) {
      ans = q1.first->sum;
    }
    root = merge(merge(q.first, q1.first), q1.second);
    return ans;
  }

  void print() {
    print(root);
  }

  bool find(long long key) {
    Node* tmp = root;
    while (tmp != nullptr) {
      if (tmp->value == key) return true;
      if (tmp->value > key) {
        tmp = tmp->left;
      }
      else {
        tmp = tmp->right;
      }
    }
    return false;
  }

  long long size() {
    return size(root);
  }

  long long height() {
    return height(root);
  }

};



int main() {
  long long n = 0;
  std::cin >> n;
  long long cur = 0;
  char c;
  long long x = 0;
  long long y = 0;
  Tree tree;
  for (long long i = 0; i < n; i++) {
    std::cin >> c;
    if (c == '+') {
      std::cin >> x;
      tree.insert((x + cur) % 1000000001);
    }
    else if (c == '-') {
      std::cin >> x;
      tree.del((x + cur) % 1000000001);
    }
    else if (c == '?') {
      std::cin >> x;
      if (tree.find((x + cur) % 1000000001)) {
        std::cout << "Found\n";
      }
      else {
        std::cout << "Not found\n";
      }
    }
    else {
      std::cin >> x >> y;
      cur = tree.sum((x + cur) % 1000000001, (y + cur) % 1000000001);
      std::cout << cur << '\n';
    }
  }
}
