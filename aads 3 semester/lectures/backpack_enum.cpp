#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>
int main() {
  int n = 0;
  std::cin >> n;
  std::vector<int> v(n);
  for (int i = 0; i < n; i++) {
    std::cin >> v[i];
  }
  std::bitset<1001> b;
  int ans = 1e9;
  for (int i = 0; i < (1 << (n-1)); i++) {
    b = i;
    int s0 = 0;
    int s1 = 0;
    for (int j = 0; j < n; j++) {
      if (b[j] == 0) {
        s0 += v[j];
      }
      else {
        s1 += v[j];
      }

      ans = std::min(ans, std::abs(s0 - s1));
    }
  }

}