#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::ostream& operator<<(std::ostream& os, const std::vector<int>& v) {
  for (size_t i = 0; i < v.size()-1; i++) {
    os << v[i] << ' ';
  }
  return os;
}

std::vector<int> lcp(std::string s, std::vector<int>& rank, std::vector<int>& suffix_array) {
  int n = s.size();
  int l = 0; 
  std::vector<int> lcp_arr(n);
  for (int i = 0; i < n; i++) {
    if (rank[i] == n - 1)
      continue;
    int nxt = suffix_array[rank[i] + 1];
    while (std::max(i, nxt) + l < n && s[i + l] == s[nxt + l])
      l++;
    lcp_arr[rank[i]] = l;
    l = std::max(0, l - 1);
  }
  return lcp_arr;
}

int main() {
  int n = 0;
  std::string s;
  std::cin >> n >> s;
  std::vector<int> suffix_array(n);
  for (int i = 0; i < n; i++) {
    std::cin >> suffix_array[i];
    suffix_array[i]--;
  }
  //std::cout << "checkpoint1 ";
  std::vector<int> rank(n);
  for (int i = 0; i < n; i++) {
    rank[suffix_array[i]] = i;
  }
  //std::cout << rank;
  //std::cout << '\n';
  std::cout << lcp(s, rank, suffix_array);

}

