#include <iostream>
#include <vector>
#include <algorithm>

struct FOO {
  long long size = 320;
  int size_ = 1;
  std::vector<long long>v;
  std::vector<long long>b;
  std::vector<std::vector<long long>> buffer;
  FOO(const std::vector<long long>& arr, long long k) {
    v = arr;
    size = std::sqrt(arr.size()) + 1;
    b = std::vector<long long>(arr.size() / size + 2, 0);
    buffer = std::vector<std::vector<long long>>(k, std::vector<long long>(3));
    //for (size_t i = 0; i < arr.size(); ++i) {
      //b[i / size] += arr[i];
    //}
  }
  long long sum(long long left, long long right) {
    long long sum = v[right + 1] - v[left];
    long long start = 0;
    long long end = 0;
    for (int i = 0; i < buffer.size(); i++) {
      end = std::min(right, buffer[i][1]);
      start = std::max(left, buffer[i][0]);
      if (!(start > right || end < left)) {
        sum += buffer[i][2] * (end - start);
      }
    }
    return sum;
  }

  void set(long long l, long long r, long long k) {
    //std::cout << '\n' << "RRRROOMBA";
    std::vector<long long> q = { l, r, k };
    buffer.push_back(q);
    if (buffer.size() > size) {}
  }

  void redo() {
    std::vector<long long> help(v.size());
    for (int i = 0; i < buffer.size(); i++) {
      help[buffer[i][0] - 1] = help[2];
      help[buffer[i][1]] = -help[2];
    }
    //for (int i = )
  }
};

long long gcd(long long num, long long den) {
  while (den) {
    num %= den;
    std::swap(num, den);
  }
  return num;
}

int main() {
  long long n = 0;
  long long k = 0;
  std::cin >> n >> k;
  while (!(n == 0 && k == 0)) {
    std::vector<long long> v(n + 1, 0);
    FOO f(v, k);
    std::string command;
    long long l = 0;
    long long r = 0;
    long long x = 0;
    for (long long i = 0; i < k; i++) {
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
          else if (den != 1) {
            std::cout << num << '/' << den << '\n';
          }
        }
        //std::cout << '\n' << num << ' ' << den;

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
