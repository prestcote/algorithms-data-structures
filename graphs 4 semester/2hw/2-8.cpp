#include <iostream>
#include <vector>
#include <queue>
#include <set>
void bfs(int n, int m, std::vector<std::vector<int>> a, std::vector<std::vector<int>>& d) {
  std::set<std::pair<int, std::pair<int, int>>> st;
  st.insert({ 0, {0, 0} });
  std::vector<std::pair<int, int> > moves = {
      {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
  while (!st.empty()) {
    int vx = st.begin()->second.first;
    int vy = st.begin()->second.second;
    st.erase(st.begin());
    for (int i = 0; i < moves.size(); ++i) {
      int x = vx;
      int y = vy;
      while (x + moves[i].first >= 0 &&
        x + moves[i].first < n &&
        y + moves[i].second >= 0 &&
        y + moves[i].second < m &&
        a[x + moves[i].first][y + moves[i].second] != 1) {
        x += moves[i].first;
        y += moves[i].second;
        if (a[x][y] == 2)
          break;
      }
      if (x >= 0 && y >= 0 && x <= n && y <= m && d[x][y] > d[vx][vy] + 1 && a[x][y] != 1)
      {
        st.erase({ d[x][y], {x, y} });
        d[x][y] = d[vx][vy] + 1;
        st.insert({ d[x][y], {x, y} });
      }
    }
  }
}

int main() {
  int n, m;
  std::cin >> n >> m;
  int inf = 1e9 + 1;
  std::vector<std::vector<int>> a(n, std::vector<int>(m));
  std::vector<std::vector<int>> d(n, std::vector<int>(m, inf));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cin >> a[i][j];
    }
  }
  d[0][0] = 0;
  bfs(n, m, a, d);
  int ans = inf;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j] == 2) {
        ans = std::min(ans, d[i][j]);
      }
    }
  }
  std::cout << ans;
  return 0;
}
