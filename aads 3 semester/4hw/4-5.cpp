#include<iostream>
#include<string>
#include<vector>

std::vector<int> mask;
std::string ans;

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

void rec2(const std::string& str, int s, int l) {
  if (ans.size() == s) {
    for (int i = 0; i < s; i++) {
      //std::cout << ans << '\n';
      std::cout << ans[i] << ' ';
      //std::cout << std::endl;
    }
    std::cout << std::endl;
  }
  else {
    for (size_t i = 0; i < mask.size(); ++i) {
      if (mask[i] < s) {
        mask[i] += 1;
        ans.push_back(str[i]);
        rec2(str, s, l);
        mask[i] -= 1;
        ans.pop_back();
      }
    }
  }
}

std::vector<int> r;

void rec2(int s, int l, int a, int b) {
  std::cout << "START!! ";
  if (r.size() == s) {
    for (int i = 0; i < s; i++) {
      std::cout << r[i] << ' ';
      std::cout << "YOHOHO" << ' ';
      std::cout << std::endl;
    }
  }
  else {
    for (size_t i = 0; i < mask.size(); i++) {
      if (mask[i] < std::pow(l, s)) {
        //std::cout << "YOHOHO" << ' ';
        mask[i] += 1;
        r.push_back(i+1);
        rec2(s, l, a, b);
        mask[i] -= 1;
        r.pop_back();
      }
    }
  }
}

int main() {
  int s, l;
  std::cin >> s >> l;
  std::string str;
  for (int i = 1; i <= l; i++) {
    str += std::to_string(i);
  }
  mask.resize(l);
  //std::vector<int> r;
  rec2(str,s, l);
}