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

long long func(int a, long long n) {
  long long k = a;
  for (int i = 2; i <= n; i++) {
    k = mul(k, k);
  }
  return k;
}

std::vector <long long> func2(int a, long long n) {
  std::vector<long long> vec(n+1, 1);
  vec[1] = a;
  int k = 0;
  for (int i = 2; i <= n; i++) {
    k = vec[i - 1];
    vec[i] = mul(k, k);
  }
  return vec;
}

int main() {
  long long n = 0;
  int a = 0;
  std::cin >> a >> n;
  //std::cout << func(a, n);
  std::vector<long long> vec = func2(a, n);
  std::cout << vec[n];
}