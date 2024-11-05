#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int x = 0;
  int y = 0;
  std::cin >> x >> y;
  std::vector<std::vector<int>> field(8, std::vector<int>(8));
  field[y-1][x-1] = 1;
  for (int i = 1; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (j == 0) {
        field[i][j] += field[i - 1][j + 1];
      }
      else if (j == 7) {
        field[i][j] += field[i - 1][j - 1];
      }
      else {
        field[i][j] += (field[i - 1][j - 1] + field[i - 1][j + 1]);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < 8; i++) {
    ans += field[7][i];
  }
  std::cout << ans;
}