#include <iostream>
#include <vector>

int main() {
  int n = 0;
  int m = 0;
  int x = 0;
  int y = 0;
  std::cin >> n >> m;
  std::vector<int> vec(n, 0);
  for (int i = 0; i < m; i++) {
    std::cin >> x >> y;
    vec[x - 1] += 1;
    vec[y - 1] += 1;
  }

  for (int i = 0; i < vec.size(); i++) {
    std::cout << vec[i] << ' ';
  }

  return 0;
}