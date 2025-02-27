#include <iostream>
#include <vector>
#include <queue>

void bfs(std::pair<int, int> start, int n, int m, std::vector<std::vector<int>>& dist) {
  std::queue<std::pair<int, int>> q;
  q.push(start);
  std::vector<std::vector<int>> used(n, std::vector<int>(m));
  std::vector < std::pair<int, int>> moves = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
  while (q.size() > 0) {
    std::pair<int, int> el = q.front();
    q.pop();
    for (int i = 0; i < moves.size(); i++) {
      int x = moves[i].first + el.first;
      int y = moves[i].second + el.second;
      if (x < n && x >= 0 && y < m && y >= 0 && used[x][y] == 0) {
        dist[x][y] = std::min(dist[x][y], dist[el.first][el.second] + 1);
        q.push({ x, y });
        used[x][y] = 1;
      }
    }
  }
}

int main() {
  int n = 0;
  int m = 0;
  int inf = 1e9;
  std::cin >> n >> m;
  std::vector<std::vector<int>> table(n, std::vector<int>(m));
  std::vector<std::vector<int>> dist(n, std::vector<int>(m, inf));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> table[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (table[i][j] == 1) {
        dist[i][j] = 0;
        bfs({ i, j }, n, m, dist);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cout << dist[i][j] << ' ';
    }
    std::cout << '\n';
  }
}