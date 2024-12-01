#include <iostream>
#include <vector>
#include <algorithm>

struct FOO {
  long long size = 320;
  std::vector<long long> v;
  std::vector<long long> b;

  FOO(const std::vector<long long>& arr) {
    v = arr;
    b = std::vector<long long>(arr.size() / size + 2, -10000000000);
    for (long long i = 0; i < arr.size(); i++) {
      b[i / size] = std::max(b[i / size], arr[i]);
    }
  }

  void set(long long left, long long right, long long num) {
    for (long long i = left; i <= right; i++) {
      v[i] += num;
    }
    long long max = -100000000000;
    long long end = std::min((long long)v.size(), (right / size) * size + size);
    for (int i = (left / size) * size; i < end; i++) {
      max = std::max(max, v[i]);
      if (i % size == 0 || i == v.size() - 1) {
        b[i / size] = max;
        max = -100000000000;
      }
    }
  }
  long long max(long long left, long long right) {
    long long max = -100000000000;
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
  int command;
  long long one = 0;
  long long two = 0;
  long long x = 0;
  int q = 0;
  std::cin >> q;
  for (int i = 0; i < q; i++) {
    std::cin >> command;
    if (command == 1) {
      std::cin >> one >> two >> x;
      f.set(one - 1, two-1, x);
    }
    else {
      std::cin >> one >> two;
      std::cout << f.max(one - 1, two - 1) << '\n';
    }
  }
  return 0;
}