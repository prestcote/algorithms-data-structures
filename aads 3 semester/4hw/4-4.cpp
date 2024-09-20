#include<iostream>
#include<string>
#include<vector>

std::vector<int> mask;
std::string ans;

void gena(const std::string& s, int n) {
  if (ans.size() == n) {
    std::cout << ans << '\n';
  }
  else {
    for (size_t i = 0; i < mask.size(); ++i) {
      if (mask[i] < n) {
        mask[i] += 1;
        ans.push_back(s[i]);
        gena(s, n);
        mask[i] -= 1;
        ans.pop_back();
      }
    }
  }
}

int main() {
  std::string s = "01";
  mask.resize(s.size());
  int n = 0;
  std::cin >> n;
  gena(s, n);
  return 0;
}