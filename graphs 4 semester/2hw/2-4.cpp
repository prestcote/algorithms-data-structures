#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

void bfs(int n, int x1, int y1, std::vector<std::vector<int>>& g, std::vector<std::vector<std::pair<int, int>>>& p) {
  std::queue<std::pair<int, int>> q;
  q.push({ x1, y1 });
  g[x1][y1] = 0;
  p[x1][y1] = { -1, -1 };
  std::vector<std::pair<int, int> > moves = {
      {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1} };
  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    for (int i = 0; i < 8; i++) {
      int u = x + moves[i].first;
      int v = y + moves[i].second;
      if (u >= 0 && u < n && v >= 0 && v < n && g[u][v] > g[x][y] + 1) {
        g[u][v] = g[x][y] + 1;
        p[u][v] = { x, y };
        q.push({ u, v });
      }

    }
  }
}

int main() {
  int n = 0;
  int x1 = 0;
  int x2 = 0;
  int y1 = 0;
  int y2 = 0;
  std::cin >> n >> x1 >> y1 >> x2 >> y2;
  std::vector<std::vector<int>> g(n, std::vector<int>(n, 1e9));
  std::vector<std::vector<std::pair<int, int>>> p(n, std::vector<std::pair<int, int>>(n));
  bfs(n, x1 - 1, y1 - 1, g, p);
  std::cout << g[x2 - 1][y2 - 1] << '\n';
  std::pair<int, int> cur = { x2 - 1, y2 - 1 };
  std::pair<int, int> b = { -1, -1 };
  std::vector<std::pair<int, int>> path;
  for (std::pair<int, int> i = cur; i != b; i = p[i.first][i.second]) {
    path.push_back(i);
  }
  std::reverse(path.begin(), path.end());
  for (int i = 0; i < path.size(); i++) {
    std::cout << path[i].first + 1 << ' ' << path[i].second + 1 << '\n';
  }
  
}