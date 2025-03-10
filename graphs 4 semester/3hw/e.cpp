#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <string> 

using matrix = std::vector<std::vector<std::vector<int>>>;

int n = 0;
int m = 0;
int ans;
std::pair<int, int> s;
std::pair<int, int> f;
matrix used;
std::vector<std::vector<int>> g;

//std::vector<int> cur(4, 0);

void bfs() {
  //std::cout << "were in";
  std::queue<std::vector<int>> q;
  q.push({ s.first, s.second, 0, 0});
  q.push({ s.first, s.second, 1, 0});
  q.push({ s.first, s.second, 2, 0});
  q.push({ s.first, s.second, 3, 0});
  //std::cout << "err cntrl 1 ";

  //used[s.first][s.second][0] = 1;
  //used[s.first][s.second][1] = 1;
  //used[s.first][s.second][2] = 1;
  //used[s.first][s.second][3] = 1;

  while (!q.empty()) {
    std::vector<int> v = q.front();
    q.pop();
    if (v[0] == f.first && v[1] == f.second) {
      //std::cout << "ALERT";
      std::cout << static_cast<int>(v[3]) << '\n';
      ans = v[3];
      return;
    }

    std::vector<std::pair<int, int>> moves = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
    int vx1 = v[1] + moves[v[2]].first;
    int vy1 = v[0] + moves[v[2]].second;

    if (!used[v[0]][v[1]][v[2]]) {
      used[v[0]][v[1]][v[2]] = 1;

      if (!g[vy1][vx1]) {
        q.push({vy1, vx1, v[2], v[3] + 1});
      }
      int right = (v[2] + 1) % 4;
      int vx2 = v[1] + moves[right].first;
      int vy2 = v[0] + moves[right].second;
      if (!g[vy2][vx2]) {
        q.push({ vy2, vx2, right, v[3] + 1});
      }
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
  g = std::vector<std::vector<int>> (n, std::vector<int>(m, 0));
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
  //std::cout << "start";
  bfs();
  //bfs(used, g, 1);
  //bfs(used, g, 2);
  //bfs(used, g, 3);
  //std::cout << ans;

  return 0;
  
}

