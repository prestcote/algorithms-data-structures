//rmq rsq дерево отрезков

#include <iostream>

template<typename Iter, typename Pred>
bool check(Iter left, Iter right, Pred f) { // [left, right)
  for (Iter it = left; it != right; ++it) {
    if (f(*it)) {
      return true;
    }
  }
  return false;
}

int main() {
  int n = 0;
  std::cin >> n;
  double* a = new double[n];
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    //std::cin >> *(a+i);
  }
  for (int i = 0; i < n; i++) {
    std::cout << *(a + i) << ' ';
    //std::cout << i[a];
  }
  std::cout << check(a, a + n, [](int a) {
    return a == 0;
    });
  delete[] a;
  return 0;
}