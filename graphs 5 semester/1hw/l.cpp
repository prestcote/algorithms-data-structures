#include <iostream>
#include <vector>

int main() {
  long long n = 0;
  long long k = 0;
  std::cin >> n >> k;
  long long ans = 0;
  for (int i = 0; i < k; i++) {
    std::cin >> ans;
  }
  std::cout << ans;
  return 0;
}
