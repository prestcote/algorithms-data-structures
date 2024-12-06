#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n = 0;
  std::cin >> n;
  std::vector<long long> v(n);
  long long max = -1;
  long long elem = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> elem;
    v[i] = elem;
    max = std::max(max, v[i]);
  }
  std::vector<long long> mask(max + 100, 0);
  long long k = 0;
  std::cin >> k;
  long long left = 0;
  long long right = 0;
  
  std::vector<std::pair<std::pair<long long, long long>, long long>> ord(k);
  for (int i = 0; i < k; i++) {
    std::cin >> left >> right;
    ord[i].first.first = left - 1;
    ord[i].first.second = right - 1;
    ord[i].second = i;
  }
  
  long long ans = 0;
  std::sort(ord.begin(), ord.end());
  for (int i = ord[0].first.first; i <= ord[0].first.second; ++i) {
    mask[v[i]] += 1;
    if (mask[v[i]] == 1) {
      ans += 1;
    }
  }
  std::vector<long long> answer(k);
  answer[ord[0].second] = ans;
  long long prev_l = ord[0].first.first;
  long long prev_r = ord[0].first.second;
  //std::cout << '\n';
  for (int i = 1; i < k; ++i) {
    left = ord[i].first.first;
    right = ord[i].first.second;
    if (prev_r < right) {
      for (long long i = prev_r + 1; i <= right; ++i) {
        mask[v[i]] += 1;
        if (mask[v[i]] == 1) {
          ans += 1;
        }
      }
    }
    if (prev_r > right) {
      for (long long i = right+1; i <= prev_r; ++i) {
        mask[v[i]] -= 1;
        if (mask[v[i]] == 0) {
          ans -= 1;
        }
      }
    }
    if (prev_l < left) {
      for (long long i = prev_l; i < left; ++i) {
        mask[v[i]] -= 1;
        if (mask[v[i]] == 0) {
          ans -= 1;
        }
      }
    }
    if (prev_l > left) {
      for (long long i = prev_l; i < left; ++i) {
        mask[v[i]] += 1;
        if (mask[v[i]] == 1) {
          ans += 1;
        }
      }
    }
    answer[ord[i].second] = ans;
    prev_l = left;
    prev_r = right;
  }
  //std::cout << '\n';
  for (int i = 0; i < k; i++) {
    std::cout << answer[i] << '\n';
  }
  
}