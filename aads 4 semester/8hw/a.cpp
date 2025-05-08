#include <vector>
#include <iostream>

void dfs(int v, int& timer, std::vector<std::vector<int>>& g, std::vector<int>& tout, std::vector<int>& tin, std::vector<int>& used) {
  used[v] = 1;
  tin[v] = timer++;
  for (int u : g[v]) {
    if (!used[u]) {
      dfs(u, timer, g, tout, tin, used);
    }
  }
  tout[v] = timer;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int n = 0;
  std::cin >> n;
  std::vector<std::vector<int>> g(n);
  int a = 0;
  int b = 0;
  int root = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> a;
    a--;
    if (a != -1) {
      g[a].push_back(i);
    }
    else {
      root = i;
    }
  }
  std::vector<int> tout(n, 0);
  std::vector<int> tin(n, 0);
  std::vector<int> used(n, 0);
  int timer = 0;
  dfs(root, timer, g, tout, tin, used);
  int m = 0;
  std::cin >> m;
  for (int i = 0; i < m; i++) {
    std::cin >> a >> b;
    a--;
    b--;
    if (tin[b] >= tin[a] && tin[b] < tout[a]) {
      std::cout << 1 << '\n';
    }
    else {
      std::cout << 0 << '\n';
    }
  }
}