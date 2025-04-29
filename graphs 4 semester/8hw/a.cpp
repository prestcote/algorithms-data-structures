#include <iostream>
#include <vector>
#include <algorithm>

int findPath(std::vector<std::vector<int>>& cap, std::vector<int>& vis, int u, int t, int f) {
  if (u == t) {
    return f;
  }
  vis[u] = 1;
  for (int v = 0; v < vis.size(); v++) {
    if (!vis[v] && cap[u][v] > 0) {
      int df = findPath(cap, vis, v, t, std::min(f, cap[u][v]));
      if (df > 0) {
        cap[u][v] -= df;
        cap[v][u] += df;
        return df;
      }
    }
  }
  return 0;
}

int maxFlow(std::vector<std::vector<int>>& cap, int s, int t) {
  for (int flow = 0;;) {
    std::vector<int> vis(cap.size(), 0);
    int df = findPath(cap, vis, s, t, 1e9);
    if (df == 0) {
      return flow;
    }
    flow += df;
  }
}

int main() {
  int n = 0;
  int m = 0;
  std::cin >> n >> m;
  std::vector<std::vector<int>> g(n, std::vector<int>(n, 0));
  int from = 0;
  int to = 0;
  int c = 0;
  for (int i = 0; i < m; i++) {
    std::cin >> from >> to >> c;
    g[from - 1][to - 1] = c;
  }
  std::cout << maxFlow(g, 0, n - 1);
}