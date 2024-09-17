#include <iostream>

double pow(int a, int n) {
  if (!n) {
    return 1;
  }
  else if (n & 1) {
    return a * pow(a, n - 1);
  }
  else {
    return pow(a*a, n / 2);
  }
}

int main() {
  int a = 0;
  int b = 0;
  std::cin >> a >> b;
  std::cout << pow(a, b);
  for (int i = 0; i < 1000; i++) {
    std::cout << pow(2, i) << ' ';
  }
}