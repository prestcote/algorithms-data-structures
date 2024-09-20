#include<iostream>
#include<string>
#include<vector>

std::vector<int> mask;
//std::string ans;
std::vector<int> ans;

void gena(const std::string& s, int n) {
  if (ans.size() == n) {
    for (int i = 0; i < n; i++) {
      std::cout << ans[i] << ' ';
    }
    //std::cout << ans << '\n';
    std::cout << std::endl;
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
  std::string s = "";
  int n, k;
  std::cin >> n >> k;
  for (int i = 1; i <= k; i++) {
    s += std::to_string(i);
  }
  mask.resize(s.size());
  gena(s, n);
  return 0;
}