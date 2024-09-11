#include <iostream>
#include <vector>

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
  int a = 0;
  int b = 0;
  std::cin >> a >> b;
  std::cout << hehehaha(b);
}