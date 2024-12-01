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
    b = std::vector<long long>(arr.size() / size + 2, -1);
    for (size_t i = 0; i < arr.size(); ++i) {
      b[i / size] = std::max(b[i / size], arr[i]);
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
    long long max = -1;
    for (long long i = begin; i < end; i++) {
      max = std::max(max, v[i]);
    }
    b[index / size] = max;
  }

  long long max(long long left, long long right) {
    long long max = -1;
    while (left <= right) {
      if (left % size == 0 && left / size != right / size) {
        max = std::max(max, b[left / size]);
        left += size;
      }
      else {
        max = std::max(v[left], max);
        ++left;
      }
    }
    return max;
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
  long long k = 0;
  std::cin >> k;
  for (int i = 0; i < k; i++) {
    std::cin >> command;
    if (command == "u") {
      std::cin >> one >> two;
      f.set(one - 1, two);
    }
    else {
      std::cin >> one >> two;
      std::cout << f.max(one - 1, two - 1) << ' ';
    }
  }
  return 0;
}
