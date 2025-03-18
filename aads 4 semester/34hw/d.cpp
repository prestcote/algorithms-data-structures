#include <iostream>
#include <random>
#include <ctime>
#include <string>

std::mt19937_64 rd(time(0));

class Tree {
private:
  struct Node {
    int32_t value = 0;
    int32_t min_v = 0;
    uint64_t prior = rd();
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int32_t value) : value(value), min_v(value) {}
    int size = 1;
    int height = 1;
  } *root = nullptr;

  int size(Node* node) {
    return node != nullptr ? node->size : 0;
  }

  int height(Node* node) {
    return node != nullptr ? node->height : 0;
  }

  int min_value(Node* node) {
    if (!node) return 1e9;
    int cur_min = 1e9;
    if (node->left != nullptr) {
      cur_min = std::min(cur_min, node->left->min_v);
    }
    if (node->right != nullptr) {
      cur_min = std::min(cur_min, node->right->min_v);
    }
    cur_min = std::min(cur_min, node->value);
    return cur_min;
  }

  void update(Node* node) {
    if (node != nullptr) {
      node->size = size(node->left) + size(node->right) + 1;
      node->height = std::max(height(node->left), height(node->right)) + 1;
      node->min_v = min_value(node);
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

  void print() {
    std::cout << size() << '\n';
    print(root);
  }

  int min(int l, int r) {
    auto q = split(root, l - 1);
    auto q1 = split(q.second, r - l + 1);
    if (q1.first == nullptr) {
      return 1e9;
    }
    int m = q1.first->min_v;
    root = merge(merge(q.first, q1.first), q1.second);
    return m;
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
  std::cin >> n;
  char c;
  int one = 0;
  int two = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> c >> one >> two;;
    if (c == '+') {
      
      tree.insert(two, one);
    }
    else {
      std::cout << tree.min(one, two) << '\n';
    }
  }
}
