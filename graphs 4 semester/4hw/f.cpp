#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

void dij(std::vector<std::vector<std::pair<int, int>>>& g, std::vector<int>& p, std::vector<int>& d, int s, std::vector<std::vector<int>>& banned) {
  d[s] = 0;
  std::priority_queue<std::pair<int, int>> q;
  q.push({ 0, s });
  while (!q.empty()) {
    int v = q.top().second;
    int cur_d = q.top().first;
    q.pop();
    if (cur_d > d[v]) {// || banned[v] == 1) {
      continue;
    }
    for (size_t i = 0; i < g[v].size(); i++) {
      int to = g[v][i].first;
      int len = g[v][i].second;
      if (d[v] + len < d[to] && !banned[to][v] && !banned[v][to]) {
        d[to] = d[v] + len;
        p[to] = v;
        q.push({ -d[to], to });
      }
    }
  }

}

int main() {
  int n = 0;
  int k = 0;
  int m = 0;
  std::cin >> n >> k >> m;
  k--;
  std::vector<std::vector<std::pair<int, int>>> g(n);
  int a;
  int b;
  int c;
  for (int i = 0; i < m; i++) {
    std::cin >> a >> b >> c;
    g[a - 1].push_back({ b - 1, c });
    g[b - 1].push_back({ a - 1, c });
  }
  std::vector<std::vector<std::pair<int, int>>> copy = g;
  std::vector<int> p(n, -1);
  std::vector<int> d(n, 1e9);
  std::vector<std::vector<int>> banned(n, std::vector<int>(n, 0));
  dij(g, p, d, k, banned);
  if (d[n - 1] == 1e9) {
    std::cout << -1;
    return 0;
  }
  for (long long i = n - 1; p[i] != -1; i = p[i]) {
    banned[i][p[i]] = 1;
    banned[p[i]][i] = 1;
  }
  //banned[n - 1] = 0;
  //banned[k] = 0;
  std::vector<int> p1(n, -1);
  std::vector<int> d1(n, 1e9);
  dij(copy, p1, d1, k, banned);
  if (d1[n - 1] == 1e9) {
    std::cout << -1;
    return 0;
  }
  std::vector<int> path;
  for (long long i = n - 1; p[i] != -1; i = p[i]) {
    path.push_back(i + 1);
  }
  path.push_back(k + 1);
  std::cout << d[n - 1] << ' ' << d1[n - 1] << '\n';
  std::vector<int> back;
  for (long long i = n - 1; p1[i] != -1; i = p1[i]) {
    back.push_back(i + 1);
  }
  back.push_back(k + 1);
  std::reverse(path.begin(), path.end());
  for (int i = 0; i < path.size(); i++) {
    std::cout << path[i] << ' ';
  }
  std::cout << '\n';
  for (int i = 0; i < back.size(); i++) {
    std::cout << back[i] << ' ';
  }
}