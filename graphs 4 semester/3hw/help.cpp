#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct State {
  int x, y, dir, dist;
};

int r, c;
vector<string> maze;
int dx[4] = { -1, 0, 1, 0 }; // Верх, Право, Низ, Лево
int dy[4] = { 0, 1, 0, -1 };

int bfs(int sx, int sy, int fx, int fy) {
  queue<State> q;
  vector<vector<vector<bool>>> visited(r, vector<vector<bool>>(c, vector<bool>(4, false)));

  for (int d = 0; d < 4; ++d) {
    q.push({ sx, sy, d, 0 });
    visited[sx][sy][d] = true;
  }

  while (!q.empty()) {
    State cur = q.front();
    q.pop();

    if (cur.x == fx && cur.y == fy) return cur.dist;

    // Прямо
    int nx = cur.x + dx[cur.dir];
    int ny = cur.y + dy[cur.dir];
    if (maze[nx][ny] != 'X' && !visited[nx][ny][cur.dir]) {
      visited[nx][ny][cur.dir] = true;
      q.push({ nx, ny, cur.dir, cur.dist + 1 });
    }

    // Направо (по часовой стрелке)
    int new_dir = (cur.dir + 1) % 4;
    if (!visited[cur.x][cur.y][new_dir]) {
      visited[cur.x][cur.y][new_dir] = true;
      q.push({ cur.x, cur.y, new_dir, cur.dist + 1 });
    }
  }
  return -1; // Не должно произойти, так как выход всегда достижим
}

int main() {
  cin >> r >> c;
  maze.resize(r);

  int sx, sy, fx, fy;
  for (int i = 0; i < r; ++i) {
    cin >> ws; // Убираем пробелы
    getline(cin, maze[i]);
    for (int j = 0; j < c; ++j) {
      if (maze[i][j] == 'S') sx = i, sy = j;
      if (maze[i][j] == 'F') fx = i, fy = j;
    }
  }

  cout << bfs(sx, sy, fx, fy) << endl;
  return 0;
}
