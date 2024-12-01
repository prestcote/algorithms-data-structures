#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

long long n = 0;

struct FOO {
  //long long size = (long long)std::sqrt(n + .0) + 1;
  long long size = 320;
  std::vector<long long>v;
  std::vector<long long>b;
  std::vector<long long>index;
  FOO(const std::vector<long long>& arr) {
    v = arr;
    b = std::vector<long long>(arr.size() / size + 2, -1);
    index = std::vector<long long>(arr.size() / size + 2);
    for (long long i = 0; i < arr.size(); ++i) {
      //b[i / size] = std::max(b[i / size], arr[i]);
      if (arr[i] > b[i / size]) {
        b[i / size] = arr[i];
        index[i / size] = i;
      }
    }
  }

  long long max(long long left, long long right) {
    long long max = -1;
    long long ans = 0;
    while (left <= right) {
      if (left % size == 0 && left / size != right / size) {
        if (max < b[left / size]) {
          max = b[left / size];
          ans = index[left/size];
          //std::cout << "KIYAAA";
        }
        left += size;
      }
      else {
        if (max < v[left]) {
          max = v[left];
          ans = left;
          //std::cout << "\nHEYYYYYY" << index << ' ';
        }
        ++left;
      }
    }
    //std::cout << "\nfound max: " << max << '\n';
   
    return ans + 1;
  }

};

int main() {
  long long n = 0;
  std::cin >> n;
  std::vector<long long>v(n);
  for (long long i = 0; i < n; i++) {
    std::cin >> v[i];
  }
  FOO f(v);
  long long one = 0;
  long long two = 0;
  long long k = 0;
  std::cin >> k;
  for (long long i = 0; i < k; i++) {
    std::cin >> one >> two;
    std::cout << f.max(one - 1, two - 1) << ' ';
  }
  return 0;
}
