#include <iostream>
#include <vector>

int main() {
  int n = 0;
  std::cin >> n;
  std::vector<std::vector<int>> vec(n, std::vector<int>(3));
  vec[0][0] = 1;
  vec[0][1] = 1;
  vec[0][2] = 1;

  for (int i = 1; i < n; i++) {
    vec[i][0] = vec[i-1][1] + vec[i-1][2];
    vec[i][1] = vec[i - 1][0] + vec[i - 1][1] + vec[i - 1][2];
    vec[i][2] = vec[i - 1][0] + vec[i - 1][1] + vec[i - 1][2];
  }
  std::cout << vec[n - 1][0] + vec[n - 1][1] + vec[n - 1][2];
  
}