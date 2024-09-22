#include<iostream>
#include<string>
#include<vector>

std::vector<int> mask;
//std::string ans;
std::vector<int> ans;

void rec(std::vector<int> r, int s, int l) {
  int count = 0;
  for (int i = 1; i <= l; i++) {
    if (r[l - 1] == s) {
      for (int i = 0; i < l; i++) {
        std::cout << r[i] << ' ';
      }
      std::cout << std::endl;
    }
    else {
      r[i] += 1;
      rec(r, s, l);
    }
  }
}

int rec1(std::vector<int> r, int s, int l) {
  for (int i = 0; i < r.size(); i++) {
    std::cout << r[i] << ' ';
  }
  std::cout << std::endl;
  int p = 0;
  while (r[s - p] == l) {
    r[s - p] = 1;
    p += 1;
    if (p == s) {
      break;
    }
  }
  if (p == s) {
    return 1;
  }
  r[s-p] = r[s-p] + 1;
  rec1(r, s, l);
}

int main() {
  int s, l;
  std::cin >> s >> l;
  std::vector<int> r(s, 1);
  rec1(r, s, l);
}