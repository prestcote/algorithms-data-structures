#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <unordered_map>

int a, h;
std::vector<int> parent, level;

bool bfs(const std::vector<std::vector<int>>& graph, const std::vector<std::unordered_map<int, int>>& capacity) {
  std::fill(parent.begin(), parent.end(), -1);
  std::fill(level.begin(), level.end(), -1);
  level[a] = 0;
  std::queue<int> q;
  q.push(a);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int u : graph[v]) {
      if (level[u] == -1 && capacity[v].count(u) && capacity[v].at(u) > 0) {
        level[u] = level[v] + 1;
        parent[u] = v;
        q.push(u);
      }
    }
  }
  return level[h] != -1;
}

int dfs(int v, int flow, const std::vector<std::vector<int>>& graph, std::vector<std::unordered_map<int, int>>& capacity) {
  if (v == h || flow == 0) return flow;
  for (int u : graph[v]) {
    if (level[u] == level[v] + 1 && capacity[v].count(u) && capacity[v][u] > 0) {
      int pushed = dfs(u, std::min(flow, capacity[v][u]), graph, capacity);
      if (pushed > 0) {
        capacity[v][u] -= pushed;
        capacity[u][v] += pushed;
        return pushed;
      }
    }
  }
  return 0;
}

int dinic(int n, const std::vector<std::vector<int>>& graph, std::vector<std::unordered_map<int, int>>& capacity) {
  int max_flow = 0;
  parent.resize(n);
  level.resize(n);
  while (bfs(graph, capacity)) {
    while (int flow = dfs(a, INT_MAX, graph, capacity))
      max_flow += flow;
  }
  return max_flow;
}

bool findPath(int u, std::vector<int>& path, std::vector<std::vector<int>>& g,
  std::vector<std::unordered_map<int, int>>& capacity,
  std::vector<std::unordered_map<int, int>>& capacity1) {
  path.push_back(u);
  if (u == h) return true;
  for (int v : g[u]) {
    if (capacity1[u].count(v) && capacity1[u].at(v) > 0) {
      if (capacity[u][v] < capacity1[u].at(v)) {
        capacity[u][v]++;
        if (findPath(v, path, g, capacity, capacity1))
          return true;
        capacity[u][v]--;
      }
    }
  }
  path.pop_back();
  return false;
}

int main() {
  int n, m;
  std::cin >> n >> m >> a >> h;
  a--;
  h--;
  std::vector<std::vector<int>> g(n);
  std::vector<std::unordered_map<int, int>> capacity(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    std::cin >> u >> v;
    u--;
    v--;
    g[u].push_back(v);
    g[v].push_back(u);
    capacity[u][v] += 1;
  }
  std::vector<std::unordered_map<int, int>> capacity1 = capacity;
  int max_flow = dinic(n, g, capacity);
  if (max_flow < 2) {
    std::cout << "NO\n";
    return 0;
  }
  std::cout << "YES\n";
  std::vector<int> path1;
  findPath(a, path1, g, capacity, capacity1);
  std::vector<int> path2;
  findPath(a, path2, g, capacity, capacity1);
  for (int i = 0; i < path1.size(); i++) {
    std::cout << path1[i] + 1 << ' ';
  }
  std::cout << '\n';
  for (int i = 0; i < path2.size(); i++) {
    std::cout << path2[i] + 1 << ' ';
  }
  return 0;
}
