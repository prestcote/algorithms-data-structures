#include <iostream>

const long long mod = 1.e9 + 9;

int gcd(int a, int b, int& x, int& y) {
  if (a == 0) {
    x = 0; y = 1;
    return b;
  }
  int x1, y1;
  int d = gcd(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return d;
}

long long find(int a) {
  if (a == 1) {
    return 1;
  }
  long long x = 1;
  while ((mod * x + 1) % a != 0) {
    x+=1;
  }
  return (mod * x + 1) / a;
}



int main()
{
  int t = 0;
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    int a = 0;
    std::cin >> a;
    int x, y;
    int g = gcd(a, mod, x, y);
    x = (x % mod + mod) % mod;
    std::cout << x << ' ';
  }
}