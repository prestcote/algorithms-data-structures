#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
std::size_t hash1(const std::string& s, int n) {
  const std::size_t p = 131;
  std::size_t h = 0;
  for (int i = 0; i < s.length(); i++) {
    h = h * p % n + static_cast<unsigned char>(s[i]);
  }
  return h % n;
}
std::size_t hash2(const std::string& s, int n) {
  const std::size_t p = 239;
  std::size_t h = 0;
  for (int i = 0; i < s.length(); i++) {
    h = h * p % n + static_cast<unsigned char>(s[i]);
  }
  return h % n;
}

std::size_t hash3(const std::string& s, int n) {
  std::size_t h = 0;
  for (int i = 0; i < s.length(); i++) {
    h = h + s[i];
  }
  return h % n;
}

class BloomFilter {
private:
  std::vector<long long> bits;
  std::size_t m; // число бит
  std::size_t k; // количество хэшей
public:
  BloomFilter(std::size_t bits, std::size_t hashes) :
    bits(bits, 0), m(bits), k(hashes) {}

  void add(const std::string& key) {
    bits[hash1(key, m)] += 1;
    bits[hash2(key, m)] += 1;
    bits[hash3(key, m)] += 1;
  }
  bool has(const std::string& key) {
    return bits[hash1(key, m)] && bits[hash2(key, m)] && bits[hash3(key, m)];
  }
  void del(const std::string& key) {
    if (has(key)) {
      bits[hash1(key, m)] = (bits[hash1(key, m)] > 0 ? --bits[hash1(key, m)] : 0);
      bits[hash2(key, m)] = (bits[hash2(key, m)] > 0 ? --bits[hash2(key, m)] : 0);
      bits[hash3(key, m)] = (bits[hash3(key, m)] > 0 ? --bits[hash3(key, m)] : 0);
    }
    
  }
};
int main() {
  std::size_t n = 5;
  std::size_t m = n * 10;
  std::size_t k = 3;

  BloomFilter bf(m, k);
  bf.add("apple");
  bf.add("pen");
  bf.add("phone");
  std::cout << "dog? " << bf.has("dog") << '\n';
  std::cout << "pen? " << bf.has("pen") << '\n';
  std::cout << "phone? " << bf.has("phone") << '\n';
  bf.del("phone");
  std::cout << "phone? " << bf.has("phone") << '\n';
  std::cout << "banana? " << bf.has("banana") << '\n';

  return 0;
}
