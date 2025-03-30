#include <iostream>
#include <vector>
#include <random>

int dsu_get(int v, std::vector<int>& p) {
  return (v == p[v] ? v : p[v] = dsu_get(p[v], p));
}

void dsu_unite(int a, int b, std::vector<int>& p, int& count) {
  a = dsu_get(a, p);
  b = dsu_get(b, p);
  if (rand() & 1) {
    std::swap(a, b);
  }
  if (a != b) {
    p[a] = b;
    count -= 1;
  }
}

int main() {
  int n = 0;
  int m = 0;
  std::cin >> n >> m;
  std::vector<int> p(n);
  for (int i = 0; i < n; i++) {
    p[i] = i;
  }
  int a = 0;
  int b = 0;
  int count = n - 1;
  for (int i = 0; i < m; i++) {
    std::cin >> a >> b;
    if (count != 0) {
      dsu_unite(a, b, p, count);
      if (count == 0) {
        std::cout << i + 1 << '\n';
      }
    }
    
  }
}