#include <iostream>
#include <vector>

int main() {
  long long n = 0;
  long long k = 0;
  std::cin >> n >> k;
  std::vector<std::vector<long long>> vec(n);
  long long b = 0;
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++) {
      std::cin >> b;
      vec[i].push_back(b);
    }
  }
  long long left = vec[0][0];
  long long right = vec[n - 1][n - 1];
  while (left < right) {
    long long m = (left + right) / 2;
    long long cntr = 0;
    long long c = n - 1;
    long long r = 0;
    while (c >= 0 && r < n) {
      if (vec[r][c] <= m) {
        cntr += (c + 1);
        r += 1;
      }
      else {
        c -= 1;
      }
    }
    if (cntr < k) {
      left = m + 1;
    }
    else {
      right = m;
    }
  }
  std::cout << left;
  return 0;
}
