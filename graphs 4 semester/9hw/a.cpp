#include <iostream>
#include <vector>

void PrintIn(std::vector<std::vector<int>>& tree, int v, std::vector<int>& val) {
  if (tree[v][0] != -1) {
    PrintIn(tree, tree[v][0], val);
  }
  std::cout << val[v] << ' ';
  if (tree[v][1] != -1) {
    PrintIn(tree, tree[v][1], val);
  }
}

void PrintPre(std::vector<std::vector<int>>& tree, int v, std::vector<int>& val) {
  std::cout << val[v] << ' ';
  if (tree[v][0] != -1) {
    PrintPre(tree, tree[v][0], val);
  }
  if (tree[v][1] != -1) {
    PrintPre(tree, tree[v][1], val);
  }
}

void PrintPost(std::vector<std::vector<int>>& tree, int v, std::vector<int>& val) {
  if (tree[v][0] != -1) {
    PrintPost(tree, tree[v][0], val);
  }
  if (tree[v][1] != -1) {
    PrintPost(tree, tree[v][1], val);
  }
  std::cout << val[v] << ' ';
}

int main() {
  int n = 0;
  std::cin >> n;
  std::vector<std::vector<int>> tree(n);
  std::vector<int> val(n);
  int key = 0;
  int l = 0;
  int r = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> key >> l >> r;
    val[i] = key;
    tree[i].push_back(l);
    tree[i].push_back(r);
  }
  //std::cout << "checkpoint 1\n";
  PrintIn(tree, 0, val);
  //std::cout << "checkpoint 2\n";
  std::cout << '\n';
  PrintPre(tree, 0, val);
  //std::cout << "checkpoint 3\n";
  std::cout << '\n';
  PrintPost(tree, 0, val);
}

