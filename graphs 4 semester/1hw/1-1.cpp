#include <iostream>

int main() {
  int n = 0;
  std::cin >> n;
  int ans = 0;
  int c = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cin >> c;
      if (i > j) {
        if (c == 1) {
          ans += 1;
        }
      }
    }
  }
  std::cout << ans;

}