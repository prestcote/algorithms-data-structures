//декартово двоичное дерево

//дерево поиска - довичное дерево, в котором выполняется соотношение поиска

#include <iostream>
#include <random>
#include <ctime>

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
  void insert(int value) {
    if (find(value)) return;
    auto q = split(root, value);
    root = merge(merge(q.first, new Node(value)), q.second);
  }

  void print() {
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
  for (int i = 0; i < 1000000; ++i) {
    tree.insert(rd() % 100000000);
  }
  //tree.print();
  std::cout << '\n' << tree.size();
  std::cout << '\n' << tree.height();
  return 0;
}
