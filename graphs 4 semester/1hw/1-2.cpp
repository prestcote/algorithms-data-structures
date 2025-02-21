#include <iostream>
#include <vector>

int main() {
  int a = 0;
  int n = 0;
  std::cin >> a >> n;
  std::vector<std::vector<int>> vec(a, std::vector<int>(a, 0));
  int x = 0;
  int y = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> x >> y;
    vec[x - 1][y - 1] = 1;
    vec[y - 1][x - 1] = 1;
  }
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < a; j++) {
      std::cout << vec[i][j] << ' ';
    }
    std::cout << '\n';
  }
  return 0;
}