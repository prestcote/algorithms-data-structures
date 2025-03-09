#include <iostream>
#include <vector>

void dfs(int v, int color, std::vector<std::vector<int>>& g, std::vector<int>& used, bool& correct) {
  for (int i = 0; i < g[v].size(); i++) {
    if (used[g[v][i]] == color) {
      correct = false;
      return;
    }
    else if (used[g[v][i]] == 0) {
      used[g[v][i]] = 3 - color;
      dfs(g[v][i], 3 - color, g, used, correct);
    }
  }
}

int main() {
  int n = 0;
  int m = 0;
  std::cin >> n >> m;
  std::vector<std::vector<int>> g(n);
  std::vector<int> used(n, 0);
  int s = 0;
  int f = 0;
  for (int i = 0; i < m; i++) {
    std::cin >> s >> f;
    g[s - 1].push_back(f - 1);
    g[f - 1].push_back(s - 1);
  }
  bool correct = true;
  for (int i = 0; i < n; i++) {
    if (used[i] == 0) {
      used[i] = 1;
      dfs(i, 1, g, used, correct);
    }
  }
  if (correct) {
    std::cout << "YES\n";
  }
  else {
    std::cout << "NO\n";
  }
}