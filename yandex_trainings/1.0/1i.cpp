#include <iostream>


int main() {
  int a, b, c, d, e;
  std::cin >> a >> b >> c >> d >> e;
  bool cond1 = (a <= d && b <= e) || (b <= d && d <= e);
  bool cond2 = (a <= d && c <= e) || (c <= d && a <= e);
  bool cond3 = (b <= d && c <= e) || (b <= e && c <= d);
  if (cond1 || cond2 || cond3) {
    std::cout << "YES";
  }
  else {
    std::cout << "NO";
  }
}