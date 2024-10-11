#include <iostream>
#include <vector>
#include <algorithm>

int binFirst(const std::vector<int>& vec, const int& key) {
  int left = -1;
  int right = vec.size();
  while (left + 1 < right) {
    int mid = (left + right) / 2;
    if (vec[mid] < key) {
      left = mid;
    }
    else {
      right = mid;
    }
  }
  if (right != vec.size() && vec[right] == key) {
    std::cout << std::endl << right << std::endl;
    return right;
  }
  else {
    std::cout << std::endl << - right << std::endl;
    return - right;
  }
}

int binLast(const std::vector<int>& vec, const int& key) {
  int left = -1;
  int right = vec.size();
  while (left + 1 < right) {
    int mid = (left + right) / 2;
    if (vec[mid] <= key) {
      left = mid;
    }
    else {
      right = mid;
    }
  }
  if (left != -1 && vec[left] == key) {
    std::cout << std::endl << left << std::endl;
    return left;
    
  }
  else {
    //return -left;
    std::cout << std::endl << -left-1 << std::endl;
    return -left-1; 
  }
}

int main() {
  std::vector<int> vec;
  std::vector<int> ans;
  int n = 0;
  std::cin >> n;
  int c = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> c;
    vec.push_back(c);
  }
  std::sort(vec.begin(), vec.end());
  /*
  for (int i = 0; i < vec.size(); i++) {
    std::cout << vec[i] << ' ';
  }
  std::cout << std::endl;
  */
  //std::cout << binLast(vec, 10);
  int k = 0;
  std::cin >> k;
  int l = 0;
  int r = 0;
  for (int i = 0; i < k; i++) {
    std::cin >> l >> r;
    int max_ = binLast(vec, r);
    int min_ = binFirst(vec, l);
    if (max_ <= 0 && min_ <= 0) {
      min_ = -min_;
      max_ = - max_;
      ans.push_back(max_ - min_);
    }
    else if (min_ < 0){
      min_ = - min_;
      ans.push_back(max_ - min_ + 1);
    }
    else if (max_ < 0){
      max_ = -max_;
      ans.push_back(max_ - min_ + 1);
    }
    //std::cout << max_ << ' ' << min_ << ' ' << max_ - min_ + 1 << std::endl;
    else {
      ans.push_back(max_ - min_ + 1);
    }
  }
  for (int i = 0; i < ans.size(); i++) {
    std::cout << ans[i] << ' ';
  }
}