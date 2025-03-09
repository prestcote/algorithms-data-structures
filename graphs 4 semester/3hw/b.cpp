#include <iostream>
#include <vector>

void check(int v, int color, std::vector<std::vector<int>>& g, std::vector<int>& mark, bool& correct) {
  if (correct == false) {
    return;
  }
  for (int i : g[v]) {
    if (mark[i] == color) {
      correct = false;
      return;
    }
    else if (mark[i] == 0) {
      mark[i] = 3 - color;
      check(i, 3 - color, g, mark, correct);
      if (correct == false) {
        return;
      }
    }
  }
}

int main() {
  int n = 0;
  int m = 0;
  std::cin >> n >> m;
  std::vector<std::vector<int>> g(n);
  std::vector<int> mark(n, 0);
  int a = 0;
  int b = 0;
  for (int i = 0; i < m; i++) {
    std::cin >> a >> b;
    g[a-1].push_back(b-1);
    g[b-1].push_back(a-1);
  }
  bool correct = true;
  for (int i = 0; i < n; i++) {
    if (mark[i] == 0) {
      mark[i] = 1;
      check(i, 1, g, mark, correct);
    }
  }
  if (correct == true) {
    std::cout << "YES\n";
    for (int i = 0; i < mark.size(); i++) {
      if (mark[i] == 1) {
        std::cout << i + 1 << ' ';
      }
    }
  }
  else {
    std::cout << "NO";
  }
}