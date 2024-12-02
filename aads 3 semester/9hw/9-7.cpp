#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

struct FOO {
  long long size = 320;
  std::vector<long long> v;
  std::vector<long long> b;

  FOO(const std::vector<long long>& arr) {
    v = arr;
    size = std::sqrt(arr.size()) + 1; 
    b = std::vector<long long>(arr.size() / size + 1, 0);
    for (size_t i = 0; i < arr.size(); ++i) {
      b[i / size] += arr[i];
    }
  }

  long long sum(long long left, long long right) {
    long long sum = 0;
    /*
    while (left <= right) {
      if (left % size == 0 && left + size - 1 <= right) {
        sum += b[left / size];
        left += size;
      }
      else {
        sum += v[left];
        ++left;
      }
    }
    */
    if (left / size == right / size) {
      for (int i = left; i <= right; ++i)
        sum += v[i];
    }
    else {
      long long end = (left / size + 1) * size - 1;
      for (int i = left; i < (left / size) * size + size; ++i)
        sum += v[i];
      for (int i = left/size + 1; i <= right/size - 1; ++i)
        sum += b[i];
      for (int i = right/size * size; i <= right; ++i)
        sum += v[i];
    }
    return sum;
  }

  void set(long long l, long long r, long long k) {
    for (long long i = l; i <= r; ) {
      if (i % size == 0 && i + size - 1 <= r) {
        long long block = i / size;
        for (long long j = block * size; j < (block + 1) * size; ++j) {
          if (j >= v.size()) break;
          if (k > v[j]) {
            b[block] += (k - v[j]);
            v[j] = k;
          }
        }
        i += size;
      }
      else {
        if (k > v[i]) {
          b[i / size] += (k - v[i]);
          v[i] = k;
        }
        ++i;
      }
    }
  }
};

long long gcd(long long a, long long b) {
  while (b) {
    a %= b;
    std::swap(a, b);
  }
  return a;
}

int main() {
  long long n = 0;
  long long k = 0;
  std::cin >> n >> k;
  while (!(n == 0 && k == 0)) {
    std::vector<long long> v(n, 0);
    FOO f(v);
    std::string command;
    long long l = 0, r = 0, x = 0;

    for (long long i = 0; i < k; ++i) {
      std::cin >> command;
      if (command == "?") {
        std::cin >> l >> r;
        long long num = f.sum(l - 1, r - 1);
        long long den = r - l + 1;
        if (num == 0) {
          std::cout << 0 << '\n';
        }
        else {
          long long g = gcd(num, den);
          num /= g;
          den /= g;
          if (den == 1) {
            std::cout << num << '\n';
          }
          else {
            std::cout << num << '/' << den << '\n';
          }
        }
      }
      else {
        std::cin >> l >> r >> x;
        f.set(l - 1, r - 1, x);
      }
    }
    std::cin >> n >> k;
  }
  return 0;
}
