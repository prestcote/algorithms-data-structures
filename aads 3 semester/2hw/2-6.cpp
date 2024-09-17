#include <iostream>
#include <vector>
const int64_t mod = 1000000 + 3;

int64_t sum(int64_t a, int64_t b) {
  return ((a % mod + b % mod) % mod + mod) % mod;
}

int64_t mul(int64_t a, int64_t b) {
  return ((a % mod * b % mod) % mod + mod) % mod;
}

int64_t sub(int64_t a, int64_t b) {
  return ((a % mod - b % mod) % mod + mod) % mod;
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

int64_t divs(int64_t a, int64_t b) {
  if (b < 0) {
    a = -a;
  }
  return mul(a, fast_pow(b, mod - 2));
}

long long fac(long long n) {
  long long b = 1;
  if (n >= 1000003) {
    return 0;
  }
  for (int i = 2; i <= n; i++) {
    b = mul(b, i);
  }
  return b;
 }

int main() {
  //std::vector<long long> fac(10e9 + 2);
  //fac[0] = 0;
  //fac[1] = 1;
  //for (long long i = 2; i < fac.size(); i++) {
  //  fac[i] = mul(fac[i - 1], i);
  //}
  int n = 0;
  std::cin >> n;
  std::cout << fac(n);
}