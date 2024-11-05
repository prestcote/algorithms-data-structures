#include <iostream>
#include <vector>

int main() {
  int n = 0;
  std::cin >> n;
  std::vector <long long> vec(n + 1);
  vec[0] = 1;
  vec[1] = 2;
  vec[2] = 4;
  for (int i = 3; i <= n; i++) {
    vec[i] = vec[i - 1] + vec[i - 2] + vec[i - 3];
  }
  std::cout << vec[n - 1];

}