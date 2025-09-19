#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

int main() {
  int n = 0;
  std::cin >> n;
  std::string str;
  std::cin >> str;
  std::map<char, int> map;
  //std::cout << "checkpoint 1\n";
  for (int i = 0; i < n; i++) {
    if (!map.count(str[i])) {
      map[str[i]] = 1;
    }
    else {
      map[str[i]] += 1;
    }
  }
  //std::cout << "checkpoint 2\n";
  std::string ans = "";
  for (auto& i : map) {
    while (i.second >= 2) {
      ans += i.first;
      i.second -= 2;
      //std::cout << map[i.first] << '\n';
    }
  }
  std::string end = ans;
  //std::cout << end << '\n';
  for (auto i : map) {
    if (i.second > 0) {
      //std::cout << i.second << ' ' << i.first << '\n';
      ans += i.first;
      break;
    }
  }
  //std::cout << ans << '\n';
  for (int i = end.size() - 1; i >= 0; i--) {
    ans += end[i];
  }
  std::cout << ans;
  return 0;
}