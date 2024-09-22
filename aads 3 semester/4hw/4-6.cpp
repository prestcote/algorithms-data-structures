#include <iostream>

void han(int n, int s, int a, int d) {
  if (n == 1) { 
    std::cout << n << ' ' << s << ' ' << d << '\n'; 
    return; 
  }
  han(n - 1, s, d, a); 
  std::cout << n << ' ' << s << ' ' << d << '\n'; 
  han(n - 1, a, s, d);
}

int main() { 
  int n; 
  std::cin >> n; 
  han(n, 1, 2, 3); 
}