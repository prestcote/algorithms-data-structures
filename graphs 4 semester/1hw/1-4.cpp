#include <iostream>
#include <vector>

void dfs(int v, std::vector<std::vector<int>>& g, int n, std::vector<int>& visit, std::vector<int>& p) {
  visit[v] = 1;
  p.push_back(v);
  for (int i = 1; i <= n; i++) {
    if (visit[i] == 0 && g[v][i] == 1) {
      dfs(i, g, n, visit, p);
      p.push_back(v);
    }
  }
}

int main() {
  int n = 0;
  int m = 0;
  int v = 0;
  std::cin >> n >> m >> v;
  std::vector<std::vector<int>> graph(n+1, std::vector<int>(n+1, 0));
  //visit.resize(n + 1);
  std::vector<int> visit(n+1, 0);
  std::vector<int> p;
  int x = 0;
  int y = 0;
  for (int i = 0; i < m; i++) {
    std::cin >> x >> y;
    graph[y][x] = 1;
    graph[x][y] = 1;
  }

  dfs(v, graph, n, visit, p);
  //p.push_back(v);
  std::cout << p.size() << '\n';
  for (int i = 0; i < p.size(); i++) {
    std::cout << p[i] << ' ';
  }
  //std::cout << " end ";
}