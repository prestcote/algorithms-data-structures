#include <iostream>

int main() {
  int n = 0;
  int k = 0;
  int m = 0;
  int count = 0;
  std::cin >> n >> k >> m;
  while (n >= k) {
    //std::cout << "YAY";
    count += (n / k) * (k / m);
    int old_n = n;
    n -= (n/k)*k;
    n += (k % m) * (old_n / k);
    //count += (k / m);
    //std::cout << n << ' ' << k << ' ' << m << std::endl;
  }
  std::cout << count;
}