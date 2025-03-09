#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <string> 

using matrix = std::vector<std::vector<std::vector<int>>>;

int n = 0;
int m = 0;
int ans = 1e9;
std::pair<int, int> s;
std::pair<int, int> f;
matrix used;

struct cur {
  int x;
  int y;
  int dir;
  int count;
};

void bfs(matrix& used, std::vector<std::vector<int>>& g, int direction) {
  std::queue<cur> q;
  q.push({ s.first, s.second, direction, 0 });
  //q.push({ s.first, s.second, 1, 0 });
  //q.push({ s.first, s.second, 2, 0 });
  //q.push({ s.first, s.second, 3, 0 });

  while (!q.empty()) {
    cur v = q.front();
    q.pop();
    if (v.x == f.first && v.y == f.second) {
      ans = std::min(v.count, ans);
      return;
    }
    std::vector<std::pair<int,  int>> moves = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
    int vx1 = v.x + moves[v.dir].first;
    int vy1 = v.y + moves[v.dir].second;
    if (g[vx1][vy1] == 0) {
      cur v1{ vx1, vy1, v.dir, v.count };
      v.count += 1;
      q.push({ vx1, vy1, v.dir, v.count });
    }
    int right = (v.dir + 1) % 4;
    int vx2 = v.x + moves[right].first;
    int vy2 = v.y + moves[right].second;
    if (g[vx1][vy1] == 0) {
      cur v2{ vx1, vy1, v.dir, v.count };
      v.count += 1;
      q.push({ vx1, vy1, v.dir, v.count });
    }
  }
}

int main() {
  int n, m;
  char c;
  std::cin >> n >> m;
  //std::cout << "minus one";
  std::cin >> c;
  //std::cout << "zero";
  std::vector<std::vector<int>> g(n, std::vector<int>(m, 0));
  used = matrix(n, std::vector<std::vector<int>>(m, std::vector<int>(4, 0)));
  std::string str;
  //std::cout << "one";
  for (int i = 0; i < n; i++) {
    //std::cout << "two";
    std::getline(std::cin, str);
    for (int j = 0; j < m; j++) {
      if (str[j] == 'S') {
        s = { i, j };
      }
      else if (str[j] == 'F') {
        f = { i, j };
      }
      else if (str[j] == 'X') {
        g[i][j] = 1;
      }
    }
  }
  std::cout << "start";
  bfs(used, g, 0);
  bfs(used, g, 1);
  bfs(used, g, 2);
  bfs(used, g, 3);
  std::cout << ans;

  return 0;
  
}

