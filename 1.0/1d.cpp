#include <iostream>

int main() {
  int a = 0;
  int b = 0;
  int c = 0;
  std::cin >> a >> b >> c;
  int d = a * a - 4 * b * c;
  if (c < 0) {
    std::cout << "NO SOLUTION";
  }
  else if (a == 0 && b == 0 && c == 0) {
    std::cout << "MANY SOLUTION";
  }
  else if (a == 0 && b != 0 && c != 0) {
    if (b == c * c) {
      std::cout << "MANY SOLUTION";
    }
    else {
      std::cout << "NO SOLUTION";
    }
  }
  else if ((a == 0 && b == 0 && c != 0) || (a == 0 && c == 0 && b != 0)) {
    std::cout << "NO SOLUTION";
  }
  else {
    std::cout << ((c * c - b) / a);
  }
}