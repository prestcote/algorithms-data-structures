#include <iostream>
#include <vector>

int main() {
  int n = 0;
  std::cin >> n;
  std::vector<long long> vec(n + 1);
  vec[0] = 1;
  vec[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (i % 2 == 0) {
      vec[i] = vec[i/2] + vec[i/2 - 1];
    }
    else {
      vec[i] = vec[(i - 1) / 2] - vec[(i - 1) / 2 - 1];
    }
  }
  std::cout << vec[n];
}