#include <iostream>

void rec(int c, int n) {
  if (c <= n) {
    std::cout << c << ' ';
    if (c < n) {
      if (c > 1) {
        std::cout << -(c - 1) << ' ';
      }
      rec(c + 1, n);
    }
  }
}

void bigrec(int n) {
  if (n > 0) {
    rec(1, n);
    bigrec(n - 2);
  }
}


int main() {
  int n = 0;
  std::cin >> n;
  bigrec(n);
}