#include <iostream>
#include <vector>
#include <random>

int dsu_get(int v, std::vector<int>& p) {
  return (v == p[v] ? v : p[v] = dsu_get(p[v], p));
}

void dsu_unite(int a, int b, std::vector<int>& p, std::vector<int>& d, int w) {
  a = dsu_get(a, p);
  b = dsu_get(b, p);
  if (rand() & 1) {
    std::swap(a, b);
  }
  if (a != b) {
    p[a] = b;
    //d[b] += w;
  }
  d[b] += w;
}

int main() {
  int n = 0;
  int k = 0;
  std::cin >> n >> k;
  std::vector<int> p(n);
  std::vector<int> d(n, 0);
  for (int i = 0; i < n; i++) {
    p[i] = i;
  }
  int c = 0;
  int a = 0;
  int b = 0;
  int w = 0;
  for (int i = 0; i < k; i++) {
    /*
    std::cout << '\n';
    for (int i = 0; i < n; i++) {
      std::cout << p[i] << ' ';
    }
    std::cout << '\n';*/
    std::cin >> c;
    if (c == 1) {
      std::cin >> a >> b >> w;
      a--;
      b--;
      dsu_unite(a, b, p, d, w);
      /*
      if (dsu_get(a, p) != dsu_get(b, p)) {
        dsu_unite(a, b, p, d, w);
      }*/
    }
    else {
      std::cin >> a;
      a--;
      std::cout << d[dsu_get(a, p)] << '\n';
    }
  }
}