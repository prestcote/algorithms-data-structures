#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>
int main() {
  int64_t n = 0;
  int64_t s = 0;
  std::cin >> s >> n;
  int64_t w = 0;
  std::bitset<10001> b = 1;
  for (int i = 0; i < n; i++) {
    std::cin >> w;
    b = b | (b << w);
  }
  int pos = 0;
  //std::cout << b << std::endl;
  for (int i = s; i >= 0; i--) {
    //std::cout << b[i] << '\n';
    if (b[i] == 1) {
      pos = i;
      break;
    }
  }
  std::cout << pos;
}