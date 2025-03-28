#include <iostream>
#include <vector>
#include <random>


int dsu_get(int v, std::vector<int>& p) {
  return (v == p[v] ? v : p[v] = dsu_get(p[v]));
}

void dsu_unite(int a, int b, std::vector<int>& p) {
  a = dsu_get(a, p);
  b = dsu_get(b, p);
  if (rand() & 1) {
    std::swap(a, b);
  }
  if (a != b) {
    p[a] = b;
  }
}

int main() {
  int n = 0;
  std::cin >> n;
  for (int i = 0; i < )
}