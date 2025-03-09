#include <iostream>
#include <vector>

int main() {
  int n = 0;
  std::cin >> n;;
  std::vector<std::vector<int>> g(n, std::vector<int>(n, 1e9));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {

    }
  }
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        g[i][j] = std::min(g[i][j], g[i][k] + g[k][j]);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cout << g[i][j] << ' ';
    }
    std::cout << '\n';
  }
}