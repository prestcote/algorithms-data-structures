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

  Node* nextone(int value) {
    Node* node = root;
    Node* ans = nullptr;
    while (node) {
      if (node->value > value) {
        ans = node;
        node = node->left;
      }
      else {
        node = node->right;
      }
    }
    if (ans) {
      //std::cout << ans->value << '\n';
      return ans;
    }
    else {
      //std::cout << "None\n";
      return nullptr;
    }
  }
  
  void next(int value) {
    auto q = nextone(value);
    if (q == nullptr) {
      std::cout << "none\n";
    }
    else {
      std::cout << q->value << '\n';
    }
  }
  /*
  Node* next(int value) {
    Node* node = root;
    Node* ans = nullptr;
    while (node) {
      if (node->value > value) {
        ans = node;
        node = node->left;
      }
      else {
        node = node->right;
      }
    }
    if (ans) {
      std::cout << ans->value << '\n';
      return ans;
    }
    else {
      std::cout << "None\n";
      return nullptr;
    }
  }
  */
  Node* previous(int value) {
    Node* node = root;
    Node* ans = nullptr;
    while (node) {
      if (node->value < value) {
        ans = node;
        node = node->right;
      }
      else {
        node = node->left;
      }
    }
    if (ans) {
      //std::cout << ans->value << '\n';
      return ans;
    }
    else {
      //std::cout << "None\n";
      return nullptr;
    }
  }
  /*
  Node* prev(int value) {
    Node* node = root;
    Node* ans = nullptr;
    while (node) {
      if (node->value < value) {
        ans = node;
        node = node->right;
      }
      else {
        node = node->left;
      }
    }
    //std::cout << "hellooo ";
    if (ans) {
      std::cout << ans->value << '\n';
      return ans;
    }
    else {
      std::cout << "None\n";
      return nullptr;
    }
  }*/
  
  void prev(int value) {
    Node* q = previous(value);
    if (q != nullptr) {
      std::cout << q->value << '\n';
    }
    else {
      std::cout << "none\n";
    }
  }

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
      update(node);
      return node;
    }
    update(node);
    return node;
  }

  void del(int v) {
    root = del(root, v);
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
  std::string c;
  int v = 0;
  while (std::cin >> c) {
    std::cin >> v;
    if (c == "insert") {
      tree.insert(v);
    }
    else if (c == "delete") {
      tree.del(v);
    }
    else if (c == "exists") {
      if (tree.find(v) == true) {
        std::cout << "true\n";
      }
      else {
        std::cout << "false\n";
      }
    }
    else if (c == "prev") {
      tree.prev(v);
    }
    else {
      tree.next(v);
    }
  }
}
