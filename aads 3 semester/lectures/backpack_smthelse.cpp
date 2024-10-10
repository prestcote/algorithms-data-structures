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
  std::bitset<30> b = 1;
  for (const auto& w : v) {
    b = b | (b << w);
  }
  std::cout << b;
}