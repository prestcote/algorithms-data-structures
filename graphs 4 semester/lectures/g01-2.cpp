#include <iostream>
#include <vector>
#include <queue>
#include <string>

void bfs(int x1, int y1, int n, std::vector<std::vector<int>>& dist) {
  std::queue<std::pair<int, int>> q;
  q.push({ x1, y1 });
  dist[x1][y1] = 0;
  std::vector<std::pair<int, int> > moves = {
      {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1} };
  while (!q.empty()) {
    int i = q.front().first;
    int j = q.front().second;
    q.pop();
    for (int k = 0; k < moves.size(); ++k) {
      int u = i + moves[k].first;
      int v = j + moves[k].second;
      if (u >= 0 && u < n && v < n && v >= 0 &&
        dist[u][v] > dist[i][j] + 1) {
        dist[u][v] = dist[i][j] + 1;
        q.push({ u, v });
      }
    }
  }
}

int main() {
  std::string first, second;
  int n = 8;
  int inf = 1e9;
  std::cin >> first >> second;
  int x1 = (int)first[0] - 'a';
  int y1 = (int)first[1] - '1';
  int x2 = (int)second[0] - 'a';
  int y2 = (int)second[1] - '1';
  std::vector<std::vector<int>> dist1(n, std::vector<int>(n, inf));
  bfs(x1, y1, n, dist1);
  std::vector<std::vector<int>> dist2(n, std::vector<int>(n, inf));
  bfs(x2, y2, n, dist2);
  int k_min = 1e9 + 1;
  int x_min = -1;
  int y_min = -1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (dist1[i][j] == dist2[i][j] && dist1[i][j] < k_min) {
        x_min = i;
        y_min = j;
        k_min = dist1[i][j];
      }
    }
  }
  if (k_min < 1e9 + 1) {
    std::cout << k_min;
  }



  else {
    std::cout << -1;
  }
}
