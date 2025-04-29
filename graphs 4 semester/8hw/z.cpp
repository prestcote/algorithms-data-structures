#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std;

int s, t;
vector<int> parent, level;

bool bfs(const vector<vector<pair<int, int>>>& graph, const vector<vector<int>>& capacity) {
  fill(parent.begin(), parent.end(), -1);
  fill(level.begin(), level.end(), -1);

  level[s] = 0;

  queue<int> q;
  q.push(s);

  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (auto& edge : graph[v]) {
      int u = edge.first;
      if (level[u] == -1 && capacity[v][u] > 0) {
        level[u] = level[v] + 1;
        q.push(u);
      }
    }
  }

  return level[t] != -1;
}

int dfs(int v, int flow, const vector<vector<pair<int, int>>>& graph, vector<vector<int>>& capacity) {
  if (v == t || flow == 0)
    return flow;

  for (auto& edge : graph[v]) {
    int u = edge.first;
    if (level[u] != level[v] + 1) continue;

    int pushed = dfs(u, min(flow, capacity[v][u]), graph, capacity);
    if (pushed) {
      capacity[v][u] -= pushed;
      capacity[u][v] += pushed;
      return pushed;
    }
  }

  return 0;
}

int dinic(int n, const vector<vector<pair<int, int>>>& graph, vector<vector<int>>& capacity) {
  int max_flow = 0;
  parent.resize(n);
  level.resize(n);
  while (bfs(graph, capacity)) {
    while (int flow = dfs(s, INT_MAX, graph, capacity))
      max_flow += flow;
  }
  return max_flow;
}

int main() {
  int n, m;
  cin >> n >> m;

  s = 0;
  t = n - 1;

  vector<vector<int>> capacity(n, vector<int>(n, 0));
  vector<vector<pair<int, int>>> graph(n);

  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    graph[u].push_back({ v, w });
    graph[v].push_back({ u, 0 });
    capacity[u][v] += w;
  }

  cout << dinic(n, graph, capacity) << endl;
  return 0;
}
