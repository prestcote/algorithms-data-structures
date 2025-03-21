#include <iostream>
#include <vector>
const int64_t mod = 1000000000 + 7;

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

int main() {
  long long a, b, c, d;
  std::cin >> a >> b >> c >> d;
  long long k = mul(a, d);
  long long m = mul(c, b);
  long long s = sum(k, m);
  long long l = mul(b, d);
  
  std::cout << divs(s, l);
}