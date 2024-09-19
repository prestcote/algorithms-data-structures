#include <iostream>
#include <vector>
const int64_t mod = 10000;

int64_t mul(int64_t a, int64_t b) {
  return ((a % mod * b % mod) % mod + mod) % mod;
}

int64_t fast_pow(int64_t a, int64_t p) {
  if (!p) {
    return 1;
  }
  else if (p & 1) {
    return a * fast_pow(a, p - 1) % mod;
  }
  else {
    return fast_pow(a * a % mod, p >> 1);
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  long long n = 0;
  int a = 0;
  std::cin >> a >> n;
  long long s = fast_pow(2, n - 1);
  long long ans = fast_pow(a, s);
  std::cout << ans;
}