#include<iostream>
#include<string>
#include<vector>

std::vector<int> mask;
//std::string ans;
std::vector<int> ans;

void rec() {

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