#include <iostream>
#include <vector>
#include <string>

std::vector<int> mask;
std::string ans;

int64_t gena(const std::string& s) {
  if (ans.size() == 3) {
    std::cout << ans << '\n';
  }
  else {
    for (size_t i = 0; i < mask.size(); i++) {
      if (mask[i] == 0) {
        mask[i] = 1;
        ans.push_back(s[i]);
        gena(s);
        mask[i] = 0;
        ans.pop_back();
      }
    }
  }
  return 0;

}

int main() {
  std::string s = "abc";
  mask.resize(s.size());
  gena(s);
}