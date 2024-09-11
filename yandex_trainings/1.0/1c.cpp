#include <iostream>
#include <string>
#include <vector>

int main() {
  std::string number = "";
  std::vector <std::string> phone;
  for (int i = 0; i < 4; i++) {
    std::cin >> number;
    std::string holder = "";
    for (int j = 0; j < number.size(); j++) {
      if ('0' <= number[j] && number[j] <= '9') {
        holder += number[j];
      }
    }
    //holder[0] = '8';
    if (holder.size() == 7) {
      holder.insert(0, "8495");
    }
    if (holder.size() == 8) {
      holder.insert(1, "495");
    }
    holder[0] = '8';
    //std::cout << holder << ' ';
    phone.push_back(holder);
  }
  //std::cout << phone[0] << ' ';
  for (int i = 1; i < 4; i++) {
    if (phone[i] == phone[0]) {
      std::cout << "YES" << std::endl;
    }
    else {
      std::cout << "NO" << std::endl;
    }
  }
  //std::cout << phone[3];
}