#include <iostream>
#include <vector>

struct edge {
  int a, b, count;
};

void solve(std::vector<edge>& e, std::vector<int>& d, int s, int k, int n, int m) {
  d[s] = 0;
  for (int i = 0; i < k; i++) {
    std::vector<int> new_d = d;
    for (int j = 0; j < m; j++) {
      if (d[e[j].a] < 1e9) {
        new_d[e[j].b] = std::min(new_d[e[j].b], d[e[j].a] + e[j].count);
      }
    }
    d = new_d;
  }
}

int main() {
  int n = 0;
  int k = 0;
  int m = 0;
  int s = 0;
  int f = 0;
  std::cin >> n >> m >> k >> s >> f;
  std::vector<edge> e;
  int si = 0;
  int fi = 0;
  int pi = 0;
  for (int i = 0; i < m; i++) {
    std::cin >> si >> fi >> pi;
    e.push_back({ si-1, fi-1, pi });
  }
  std::vector<int> d(n, 1e9);
  solve(e, d, s - 1, k, n, m);
  if (d[f - 1] == 1e9) {
    std::cout << -1;
    return 0;
  }
  else {
    std::cout << d[f - 1];

  }
  return 0;

}