#include <iostream>
#include <vector>
#include <random>
#include <string>

int dsu_get(int v, std::vector<int>& p) {
  return (v == p[v] ? v : p[v] = dsu_get(p[v], p));
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
  int m = 0;
  int k = 0;
  int h = 0;
  std::cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    std::cin >> h >> h;
  }
  std::vector<std::vector<int>> vec;
  std::string com;
  int c = 0;
  int a = 0;
  int b = 0;
  for (int i = 0; i < k; i++) {
    std::cin >> com >> a >> b;
    if (com == "ask") {
      c = 1;
    }
    else {
      c = 2;
    }
    vec.push_back({ c, a - 1, b - 1 });
  }
  std::vector<std::string> ans;
  std::vector<int> p(n);
  for (int i = 0; i < n; i++) {
    p[i] = i;
  }
  for (int i = k-1; i >= 0; i--) {
    if (vec[i][0] == 1) {
      if (dsu_get(vec[i][1], p) == dsu_get(vec[i][2], p)) {
        ans.push_back("YES");
      }
      else {
        ans.push_back("NO");
      }
    }
    else {
      dsu_unite(vec[i][1], vec[i][2], p);
    }
  }
  for (int i = ans.size()-1; i >= 0; i--) {
    std::cout << ans[i] << '\n';
  }
}