#include <iostream>

void rec(int n, int count) {
  int a = 0;
  std::cin >> a;
  if (count < n) {
    rec(n, count+1);
  }
  std::cout << a << ' ';
}

int main() {
  int n = 0;
  std::cin >> n;
  rec(n, 1);
}