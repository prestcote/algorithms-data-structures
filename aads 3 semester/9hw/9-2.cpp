#include <iostream>
#include <vector>
#include <algorithm>

struct FOO {
  long long size = 320;
  std::vector<long long> v;
  std::vector<long long> b;
  std::vector<long long> add;

  FOO(const std::vector<long long>& arr) {
    v = arr;
    b = std::vector<long long>(arr.size() / size + 2, -1e10);
    add = std::vector<long long>(b.size(), 0);
    for (long long i = 0; i < arr.size(); i++) {
      b[i / size] = std::max(b[i / size], arr[i]);
    }
  }

  void set(long long left, long long right, long long num) {
    long long int max = -1e100;
    for (int i = left / size * size; i < std::min((long long)v.size(), left / size * size + size); ++i) {
      if (i >= left && i <= right) {
        v[i] += num;
      }
      max = std::max(max, v[i]);
    }
    b[left / size] = max;

    for (int i = std::min((long long)v.size(), left / size * size + size); i <= right / size * size - size; i += size) {
      add[i / size] += num;
    }

    max = -1e100;
    if (left / size != right / size) {
      for (int i = right / size * size; i < std::min((long long)v.size(), right / size * size + size); ++i) {
        if (i >= left && i <= right) {
          v[i] += num;
        }
        max = std::max(max, v[i]);
      }
      b[right / size] = max;
    }
  }

  long long max(long long left, long long right) {
    long long max = -1e100;
    while (left <= right) {
      if (left % size == 0 && left / size != right / size) {
        max = std::max(max, b[left / size] + add[left / size]);
        left += size;
      }
      else {
        max = std::max(v[left] + add[left / size], max);
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
  long long q = 0;
  std::cin >> q;
  for (long long i = 0; i < q; i++) {
    std::cin >> command;
    if (command == 1) {
      std::cin >> one >> two >> x;
      f.set(one - 1, two - 1, x);
    }
    else {
      std::cin >> one >> two;
      std::cout << f.max(one - 1, two - 1) << '\n';
    }

  }
  return 0;
}