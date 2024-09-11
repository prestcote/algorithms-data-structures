#include <iostream>
#include <vector>

std::vector<bool> alg(int x) {
  std::vector<bool> vec(x + 1, true);
  for (int i = 2; i <= x; i++) {
    if (vec[i]) {
      for (int j = 2 * i; j <= x; j += i) {
        vec[j] = false;
      }
    }
  }
  return vec;
}

int hehehaha(int x) {
  std::vector<bool> vec(x + 1, true);
  int count = 0;
  for (int i = 2; i <= x; i++) {
    if (vec[i]) {
      count += 1;
      for (int j = 2 * i; j <= x; j += i) {
        vec[j] = false;
      }
    }
  }
  return count;
}

int main() {
  int x = 0;
  std::cin >> x;
  int ans = 0;
  ans = hehehaha(x);
  std::cout << ans;
  
}