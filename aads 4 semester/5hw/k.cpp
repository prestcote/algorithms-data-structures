#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define Min(a, b) ((a) < (b) ? (a) : (b))

std::ostream& operator<<(std::ostream& os, const std::vector<long long>& v) {
  for (size_t i = 1; i < v.size(); i++) {
    os << v[i] + 1 << ' ';
  }
  return os;
}

std::vector <long long> suffix_array(std::string s) {
  s += '\0';
  size_t n = s.size();
  //std::cout << n << '\n';
  //std::cout << s << '\n';
  std::vector<long long> c(n);
  std::vector<long long> p(n);
  std::vector<std::pair<long long, long long>> pairs(n);

  for (long long i = 0; i < n; ++i) {
    p[i] = i;
  }
  std::sort(p.begin(), p.end(), [&](long long i, long long j) {
    return s[i] < s[j];
    });
  //std::cout << p << '\n';

  c[p[0]] = 0;
  for (long long i = 1; i < n; ++i) {
    c[p[i]] = c[p[i - 1]] + (s[p[i]] != s[p[i - 1]]);
  }
  //std::cout << c;

  for (long long len = 1; len < n; len *= 2) {
    for (long long i = 0; i < n; ++i) {
      pairs[i] = { c[i], c[(i + len) % n] };
    }
    std::sort(p.begin(), p.end(), [&](long long i, long long j) {
      return pairs[i] < pairs[j];
      });
    c[p[0]] = 0;
    for (long long i = 1; i < n; ++i) {
      c[p[i]] = c[p[i - 1]] + (pairs[p[i]] != pairs[p[i - 1]]);
    }
  }

  return std::vector<long long>(p.begin() + 1, p.end());
}

std::vector<long long> lcp(std::string s, std::vector<long long>& rank, std::vector<long long>& suffix_array) {
  long long n = s.size();
  long long l = 0;
  std::vector<long long> lcp_arr(n);
  for (long long i = 0; i < n; i++) {
    if (rank[i] == n - 1)
      continue;
    long long nxt = suffix_array[rank[i] + 1];
    while (std::max(i, nxt) + l < n && s[i + l] == s[nxt + l])
      l++;
    lcp_arr[rank[i]] = l;
    if (l - 1 > 0) {
      l -= 1;
    }
    else {
      l = 0;
    }
    //l = std::max(0, l - 1);
  }
  return lcp_arr;
}

int main() {
  std::string s;
  std::getline(std::cin, s);
  long long n = s.size();
  std::vector<long long> suff_array = suffix_array(s);
  //std::cout << "checkpoint 1\n";
  std::vector<long long> rank(s.size());
  for (long long i = 0; i < s.size(); i++) {
    rank[suff_array[i]] = i;
  }
  //std::cout << "checkpoint 2\n";
  std::vector<long long> l = lcp(s, rank, suff_array);
  //std::cout << "checkpoint 3\n";
  long long repeat = 0;
  long long sum = 0;
  for (long long i = 0; i < n; i++) {
    sum += (n - suff_array[i]);
  }
  for (long long i = 0; i < l.size(); i++) {
    repeat += l[i];
  }
  //std::cout << "checkpoint 4\n";
  //std::cout << sum << ' ' << repeat << ' ' << sum - repeat;
  std::cout << sum - repeat;
}