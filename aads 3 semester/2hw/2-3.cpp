#include <iostream>

//произведение остатков должно делиться по модулю с таким же остатком что и 
//сами числа
const long long mod = 1.e9 + 9;

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
  int a = 0;
  for (int i = 0; i < t; i++) {
    std::cin >> a;
    std::cout << find(a);
  }
}