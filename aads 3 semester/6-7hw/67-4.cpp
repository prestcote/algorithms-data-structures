#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n = 0;
  int m = 0;
  int money = 0;
  std::cin >> n >> m;
  std::vector<std::vector<double>> field(n, std::vector<double>(m, 1));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> money;
      if (j == 0 && i == 0) {
        field[i][j] = money;
      }
      else if (j == 0 && i != 0) {
        field[i][j] = money + field[i - 1][j];
      }
      else if (j != 0 && i == 0) {
        field[i][j] = money + field[i][j - 1];
      }
      else {
        field[i][j] = money + std::max(field[i-1][j], field[i][j-1]);
      }
    }
  }
  std::cout << field[n - 1][m - 1];
}