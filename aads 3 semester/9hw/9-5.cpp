#include <iostream>
#include <vector>

struct FOO {
  long long size = 320;
  std::vector<long long>v;
  std::vector<long long>b;
  FOO(const std::vector<long long>& arr) {
    v = arr;
    size = std::sqrt(arr.size()) + 1;
    b = std::vector<long long>(arr.size() / size + 2, 0);
    //for (size_t i = 0; i < arr.size(); ++i) {
      //b[i / size] += arr[i];
    //}
  }
  long long sum(long long left, long long right) {
    long long sum = 0;
    while (left <= right) {
      if (left % size == 0 && left / size != right / size) {
        sum += b[left / size];
        left += size;
        //std::cout << sum << ' ';
      }
      else {
        sum += v[left];
        ++left;
        //std::cout << sum << ' ';
      }
    }
    return sum;
  }

  void set(long long l, long long r, long long k) {
    //std::cout << '\n' << "RRRROOMBA";
    for (long long i = l; i <= r; i++) {
      if (k > v[i]) {
        b[i / size] += (k - v[i]);
        v[i] = k;
        //std::cout << b[i / size] << ' ' << k << ' ' << v[i] << "STOP";
      }
    }
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
    std::vector<long long> v(n, 0);
    FOO f(v);
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
