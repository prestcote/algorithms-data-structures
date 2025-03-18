#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n = 0;
  int m = 0;
  std::cin >> n >> m;
  int s = 0;
  int e = 0;
  std::cin >> s >> e;
  int i = 0;
  int j = 0;
  double p = 0;
  std::vector<std::vector<double>> g(n, std::vector<double>(n, -1));
  for (int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if (i == j) {
        g[i][j] = 0;
      }
    }
  }
  for (int k = 0; k < m; k++) {
    std::cin >> i >> j >> p;
    g[i - 1][j - 1] = (100.0-p)/100.0;
    g[j - 1][i - 1] = (100.0-p)/100.0;
    //std::cout << g[i - 1][j - 1] << ' ';
  }

  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        g[i][j] = std::max(g[i][j], g[i][k] * g[k][j]);
      }
    }
  }
  /*
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cout << g[i][j] << ' ';
    }
    std::cout << '\n';
  }*/
  std::cout << 1.0-g[s - 1][e - 1];
  return 0;
}