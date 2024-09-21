#include <iostream>
#include <vector>
#include <string>
#include <set>

std::set<std::string> func(std::string str) {
  std:: set<std::string> s;
  for (int i = 0; i < str.size(); i++) {
    std::string head = str.substr(i) + str.substr(0, i);
    s.insert(head);
  }
  return s;
}


int main() {
  std::string s;
  std::cin >> s;
  std::set<std::string> sett = func(s);
  int n = 0;
  std::cin >> n;
  int count = 0;
  if (n > sett.size()) {
    std::cout << "IMPOSSIBLE";
  }
  else {
    for (std::string i : sett) {
      //std::cout << i << ' ';
      count += 1;
      if (count == n) {
        std::cout << i << std::endl;
        break;
      }
    }

  }
  //std::cout << *(&sett.begin() + n);
}