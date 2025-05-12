#include <iostream>
#include <vector>

template<typename T>
class AvlTree {
private:
  struct Node {
    Node* left = nullptr;
    Node* right = nullptr;
    T key = 0;
    size_t height = 1;
    Node(T val) : key(val) {}
    Node() = default;
  } *root = nullptr;

  int Height(Node* node) {
    return (node == nullptr) ? 0 : node->height;
  }

  int BalanceFactor(Node* node) {
    return (node == nullptr) ? 0 : Height(node->left) - Height(node->right);
  }

  void Update(Node* node) {
    if (node != nullptr) {
      node->height = 1 + std::max(Height(node->left), Height(node->right));
    }
  }

  Node* RightRotation(Node* y) {
    Node* x = y->left;
    Node* node = x->right;
    x->right = y;
    y->left = node;
    Update(y);
    Update(x);
    return x;
  }

  Node* LeftRotation(Node* x) {
    Node* y = x->right;
    Node* node = y->left;
    y->left = x;
    x->right = node;
    Update(x);
    Update(y);
    return y;
  }

  Node* Balance(Node* node) {
    if (node == nullptr) {
      return nullptr;
    }
    Update(node);
    int bal_fac = BalanceFactor(node);
    if (bal_fac > 1) {
      if (BalanceFactor(node->left) >= 0) {
        return RightRotation(node);
      }
      else {
        node->left = LeftRotation(node->left);
        return RightRotation(node);
      }
    }
    if (bal_fac < -1) {
      if (BalanceFactor(node->right) <= 0) {
        return LeftRotation(node);
      }
      else {
        node->right = RightRotation(node->right);
        return LeftRotation(node);
      }
    }
    return node;
  }

  Node* Insert(Node* node, int key) {
    if (node == nullptr) {
      return new Node(key);
    }
    if (key < node->key) {
      node->left = Insert(node->left, key);
    }
    else if (key > node->key) {
      node->right = Insert(node->right, key);
    }
    else {
      return node;
    }
    return Balance(node);
  }

  void PrintIn(Node* node) {
    if (node == nullptr) {
      return;
    }
    PrintIn(node->left);
    std::cout << node->key << ' ';
    PrintIn(node->right);
  }

  void PrintPre(Node* node) {
    if (node == nullptr) {
      return;
    }
    std::cout << node->key << ' ';
    PrintPre(node->left);
    PrintPre(node->right);
  }

  void PrintPost(Node* node) {
    if (node == nullptr) {
      return;
    }
    PrintPost(node->left);
    PrintPost(node->right);
    std::cout << node->key << ' ';
  }

public:
  explicit AvlTree() = default;
  AvlTree(AvlTree&& t) {}
  ~AvlTree() {
    delete root;
  }

  void Insert(T val) {
    root = Insert(root, val);
  }

  void PrintIn() {
    PrintIn(root);
  }

  void PrintPre() {
    PrintPre(root);
  }

  void PrintPost() {
    PrintPost(root);
  }
};

int main() {
  int n = 0;
  std::cin >> n;
  AvlTree<int> avl;
  int x = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> x;
    avl.Insert(x);
  }
}