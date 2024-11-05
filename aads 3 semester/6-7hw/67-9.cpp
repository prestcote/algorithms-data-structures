#include <iostream>
#include <vector>

int main() {
  int x = 0;
  std::cin >> x;
  std::vector<std::vector<int>> vec(x+1);
  vec[1] = { 1 };
  for (int i = 2; i <= x; i++) {
    vec[i] = vec[i - 1];
    if (i % 2 == 0) {
      if (vec[i / 2].size() < vec[i].size()) {
        vec[i] = vec[i / 2];
      }
    }
    if (i % 3 == 0) {
      if (vec[i / 3].size() < vec[i].size()) {
        vec[i] = vec[i / 3];
      }
    }
    vec[i].push_back(i);
  }
  std::cout << vec[x].size()-1 << std::endl;
  for (int i = 0; i < vec[x].size(); i++) {
    std::cout << vec[x][i] << ' ';
  }
}