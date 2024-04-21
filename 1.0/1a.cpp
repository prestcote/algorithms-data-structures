#include <iostream>
#include <string>

int main() {
  int troom = 0;
  int tcond = 0;
  std::string word = "";
  std::cin >> troom >> tcond >> word;
  if (word == "fan") {
    std::cout << troom;
  }
  else if (word == "auto") {
    std::cout << tcond;
  }
  else if (word == "freeze") {
    if (troom <= tcond) {
      std::cout << troom;
    }
    else {
      std::cout << tcond;
    }
  }
  else if (word == "heat") {
    if (troom >= tcond) {
      std::cout << troom;
    }
    else {
      std::cout << tcond;
    }
  }
}