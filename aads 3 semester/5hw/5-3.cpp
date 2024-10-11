#include <iostream>

int main() {
  long long n = 0;
  long long m = 0;
  std::cin >> n >> m;
  long long ost = n % m;
  long long ans = 1;
  for (int i = 0; i < n; i++) {
    ans = (ans * ost) % m;
  }
  std::cout << ans;
}