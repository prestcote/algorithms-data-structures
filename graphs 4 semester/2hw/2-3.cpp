#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

void bfs(int v, std::vector<std::vector<int>>& g, std::vector<int>& d, std::vector<int>& p) {
  std::queue<int> q;
  q.push(v);
  std::vector<int> used(g.size(), 0);
  used[v] = 1;
  p[v] = -1;
  d[v] = 0;
  while (!q.empty()) {
    int s = q.front();
    q.pop();
    for (int to : g[s]) {
      if (used[to] == 0) {
        used[to] = 1;
        q.push(to);
        d[to] = d[s] + 1;
        p[to] = s;
      }
    }
  }
}

int main() {
  int n = 0;
  std::cin >> n;
  std::vector<std::vector<int>> g(n);
  int c = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cin >> c;
      if (c == 1) {
        g[i].push_back(j);
        g[j].push_back(i);
      }
    }
  }
  int f = 0;
  int t = 0;
  std::cin >> f >> t;
  std::vector<int> d(n, 1e9);
  std::vector<int> p(n, -1);
  bfs(f-1, g, d, p);
  int dist = d[t - 1];
  if (dist == 1e9) {
    std::cout << -1 << '\n';
  }
  else if (dist == 0) {
    std::cout << dist << '\n';
  }
  else {
    std::cout << dist << '\n';
    std::vector<int> path;
    for (int i = t-1; i != -1; i=p[i]) {
      path.push_back(i);
      //std::cout << p[t - 1] << ' ';
      //t = p[t - 1] + 1;
    }
    std::reverse(path.begin(), path.end());
    for (int i = 0; i < path.size(); i++) {
      std::cout << path[i] + 1 << ' ';
    }
  }
}