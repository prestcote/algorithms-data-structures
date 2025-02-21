#include <iostream>
#include <vector>

int main() {
  int n = 0;
  std::cin >> n;
  std::string s;
  std::vector<int> vec;
  for (int i = 0; i < n; i++) {
    std::cin >> s;
    int cnt = 0;
    vec.clear();
    for (int j = 0; j < n; j++) {
      if (s[j] == '1') {
        cnt += 1;
        vec.push_back(j + 1);
      }
    }
    std::cout << cnt << ' ';
    for (int k = 0; k < vec.size(); k++) {
      std::cout << vec[k] << ' ';
    }
    std::cout << '\n';
  }
  return 0;
}