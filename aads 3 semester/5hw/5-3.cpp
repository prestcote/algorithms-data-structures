#include <iostream>

int64_t fast_pow(int64_t a, int64_t p, int64_t mod) {
  if (!p) {
    return 1;
  }
  else if (p & 1) {
    return a * fast_pow(a, p - 1, mod) % mod;
  }
  else {
    return fast_pow(a * a % mod, p >> 1, mod);
  }
}

int main() {
  unsigned long long n = 0;
  unsigned long long m = 0;
  std::cin >> n >> m;
  unsigned long long ost = n % m;
  unsigned long long ans = fast_pow(ost, n, m);
  std::cout << ans%m;
}