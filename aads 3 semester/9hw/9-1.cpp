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
  FOO(const std::vector<long long>& arr) {
    v = arr;
    b = std::vector<long long>(arr.size() / size + 2, 10000000000);
    for (size_t i = 0; i < arr.size(); ++i) {
      b[i / size] = std::min(b[i/size], arr[i]);
    }
  }

  void set(long long index, long long num) {
    v[index] = num;
    long long end = 0;
    if (index / size * size + size > v.size()) {
      end = v.size();
    }
    else {
      end = index / size * size + size;
    }
    long long begin = index / size * size;
    long long min = 100000000000;
    for (long long i = begin; i < end; i++) {
      min = std::min(min, v[i]);
    }
    b[index / size] = min;
  }

  long long min(long long left, long long right) {
    long long min = 10000000000;
    while (left <= right) {
      if (left % size == 0 && left / size != right / size) {
        min = std::min(min, b[left / size]);
        left += size;
      }
      else {
        min = std::min(v[left], min);
        ++left;
      }
    }
    return min;
  }


};

int main() {
  long long n = 0;
  std::cin >> n;
  std::vector<long long>v(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> v[i];
  }
  FOO f(v);
  std::string command;
  long long one = 0;
  long long two = 0;
  while (std::cin >> command) {
    if (command == "set") {
      std::cin >> one >> two;
      f.set(one - 1, two);
    }
    else {
      std::cin >> one >> two;
      std::cout << f.min(one - 1, two - 1) << '\n';
    }
  }
  return 0;
}
