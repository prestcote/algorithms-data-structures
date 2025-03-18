#include <iostream>
#include <random>
#include <ctime>
#include <string>
#include <algorithm>

std::mt19937_64 rd(time(0));

class Tree {
private:
  struct Node {
    int32_t value = 0;
    uint64_t prior = rd();
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int32_t value) : value(value) {}
    int size = 1;
    int height = 1;
  } *root = nullptr;

  int size(Node* node) {
    return node != nullptr ? node->size : 0;
  }

  void update(Node* node) {
    if (node != nullptr) {
      node->size = size(node->left) + size(node->right) + 1;
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

  std::pair<Node*, Node*> split(Node* curr, int key) {
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

public:

  void insert(int value) {
    if (find(value)) return;
    auto q = split(root, value);
    root = merge(merge(q.first, new Node(value)), q.second);
  }

  Node* del(Node* node, int value) {
    //if (!find(value)) return nullptr;
    if (!node) return nullptr;
    //Node* node = root;
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

  void del(int v) {
    root = del(root, v);
  }

  int max(Node* node, int k) {

    //if (!node) return 0;
    int size_ = size(node->right);
    if (size_ == k - 1) {
      return node->value;
    }
    else if (size_ >= k)
      return max(node->right, k);
    else {
      //k -= size(node->right) + 1;
      return max(node->left, k - (size_ + 1));
    }
  }

  int max(int k) {
    return max(root, k);
  }

  bool find(int key) {
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

};

int main() {
  Tree tree;
  int n = 0;
  std::cin >> n;
  int str = 0;
  int c = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> str >> c;
    if (str == -1) {
      tree.del(c);
    }
    else if (str == 0) {
      std::cout << tree.max(c) << '\n';
    }
    else {
      tree.insert(c);
    }
  }
}