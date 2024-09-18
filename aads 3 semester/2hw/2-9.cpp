#include <iostream>
#include <vector>


std::vector<int> div_count() {
  std::vector<int> vec(1000001, 1);
  for (int i = 2; i < vec.size()/2; i++) {
    for (int j = i+i; j < vec.size(); j += i) {
      vec[j] += i;
    }
  }
  return vec;
}

int main() {
  std::vector<int> vec = div_count();
  int n = 0;
  int k = 0;
  std::cin >> n >> k;
  int t = 0;
  bool flag = false;
  for (int i = n; i <= k; i++) {
    t = vec[i];
    if (t <= k && t >= n && vec[t] == i && i < t) {
      std::cout << i << ' ' << t << '\n';
      flag = true;
    }
  }
  if (flag == false) {
    std::cout << "Absent";
  }
}