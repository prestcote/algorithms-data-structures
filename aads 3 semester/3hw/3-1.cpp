#include <iostream>
#include <map>
#include <string>
#include <vector>



int main() {
  std::map<unsigned, std::string> book;
  int n;
  std::cin >> n;
  //std::cout << n << '\n';
  int number;
  std::string comm, name;
  for (int i = 0; i < n; ++i) {
    //std::cout << "yahoo";
    std::cin >> comm;
    //std::cout << name;
    if (comm == "add") {
      std::cin >> number;
      std::cin >> name;
      book[number] = name;
    }
    else if (comm == "del") {
      std::cin >> number;
      book.erase(number);
    }
    else if (comm == "find") {
      std::cin >> number;
      bool flag = false;
      auto it = book.find(number);
      if (it != book.end()) {
        std::cout << book[number] << std::endl;
      }
      else {
        std::cout << "not found" << std::endl;
      }
      /*
      for (const auto& num : book) {
        if (num.first == number) {
          std::cout << num.second << std::endl;
          flag = true;
        }
      }
      if (flag == false) {
        std::cout << "not found" << std::endl;
      }
      */
    }
  }
}