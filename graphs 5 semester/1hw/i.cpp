#include <iostream>
#include <vector>

int main() {
  int a = 0;
  int b = 0;
  std::cin >> a >> b;
  int n = (a ^ b) ^ a;
  int m = (n ^ b) ^ a;
  std::cout << n << ' ' << m;


}
