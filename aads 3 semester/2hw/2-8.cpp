#include <iostream>
#include <vector>

int64_t fast_pow(long long a, long long p, long long mod) {
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

int64_t mul(long long a, long long b, long long mod) {
  return ((a % mod * b % mod) % mod + mod) % mod;
}

int64_t sum(long long a, long long b, long long mod) {
  return ((a % mod + b % mod) % mod + mod) % mod;
}

int64_t divs(int64_t a, int64_t b, int64_t mod) {
  if (b < 0) {
    a = -a;
  }
  return mul(a, fast_pow(b, mod - 2, mod), mod);
}

long long gcd(long long a, long long b, long long& x, long long& y) {
  if (a == 0) {
    x = 0; y = 1;
    return b;
  }
  long long x1, y1;
  long long d = gcd(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return d;
}

long long func(int64_t a, int64_t n, int64_t mod) {

  long long an = fast_pow(a, n, mod);
  long long x, y;
  long long g = gcd(an, mod, x, y);
  if (g != 1)
    return -1;
  else {
    x = (x % mod + mod) % mod;
  }

  long long summ = 0;
  long long j = 0;
  while (j != n + 1) {
    long long k = mul(n-j, x, mod);
    summ = sum(k, summ, mod);
    j += 1;
    x = mul(x, a, mod);
  }
  return summ;
}

int main() {
  long long a, n, mod;
  std::cin >> a >> n >> mod;
  std::cout << func(a, n, mod);
}