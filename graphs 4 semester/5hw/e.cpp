#include <iostream>
#include <vector>

struct edge {
  long long a, b, cost;
};

void solve(std::vector<edge>& e, long long v, std::vector<long long>& d, long long n, long long m) {
  d[v] = 0;
  for (size_t i = 0; i < n - 1; i++) {
    bool any = false;
    for (size_t j = 0; j < m; j++) {
      if (d[e[j].a] < 1e18) {
        if (d[e[j].b] > d[e[j].a] + e[j].cost) {
          d[e[j].b] = d[e[j].a] + e[j].cost;
          any = true;
        }
      }
    }
    if (!any) {
      break;
    }
  }
}

int main() {
  long long n = 0;
  long long m = 0;
  long long s = 0;
  long long t = 0;
  std::cin >> n >> m >> s >> t;
  std::vector<edge> e;
  long long a = 0;
  long long b = 0;
  long long w = 0;
  for (size_t i = 0; i < m; i++) {
    std::cin >> a >> b >> w;
    e.push_back({ a - 1, b - 1, w });
  }
  std::vector<long long> d(n, 1e18);
  solve(e, s-1, d, n, m);
  std::cout << d[t - 1];
}