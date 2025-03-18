#include <iostream>
#include <random>
#include <ctime>
#include <string>

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

  int height(Node* node) {
    return node != nullptr ? node->height : 0;
  }

  void update(Node* node) {
    if (node != nullptr) {
      node->size = size(node->left) + size(node->right) + 1;
      node->height = std::max(height(node->left), height(node->right)) + 1;
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
    int l_size = size(curr->left);
    if (key <= l_size) {
      auto q = split(curr->left, key);
      curr->left = q.second;
      update(curr);
      return { q.first, curr };
    }
    auto q = split(curr->right, key - l_size - 1);
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

  void insert(int value, int pos) {
    //if (find(value)) return;
    auto q = split(root, pos);
    root = merge(merge(q.first, new Node(value)), q.second);
  }

  void del(int value) {
    //Node* node = root;
    auto q = split(root, value);
    auto q1 = split(q.second, 1);
    delete q1.first;
    root = merge(q.first, q1.second);
  }

  void print() {
    std::cout << size() << '\n';
    print(root);
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

  int size() {
    return size(root);
  }

  int height() {
    return height(root);
  }

};



int main() {
  Tree tree;
  int n = 0;
  int m = 0;
  std::cin >> n >> m;
  int c = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> c;
    tree.insert(c, i);
  }
  std::string s;
  int one = 0;
  int two = 0;
  for (int i = 0; i < m; i++) {
    std::cin >> s;
    if (s == "del") {
      std::cin >> one;
      tree.del(one-1);
    }
    else {
      std::cin >> one >> two;
      tree.insert(two, one);
    }
    //std::cout << '\n';
    //tree.print();
    //std::cout << '\n';
  }
  tree.print();
}
