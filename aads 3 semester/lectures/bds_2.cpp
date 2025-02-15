#include <iostream>
#include <map>

int main() {
  int m = 0;
  int n = 0;
  std::cin >> m >> n;
  int a = 0;
  int b = 0;
  std::map<int, int> disk;
  for (int i = 1; i <= n; i++) {
    std::cin >> a >> b;
    auto help = disk.lower_bound(a);
    if (help != disk.begin()) {
      help--;
      if (help->second < a) {
        help++;
      }
    }
    while (help != disk.end() && help->first <= b) {
      help = disk.erase(help);
    }
    disk[a] = b;
  }
  std::cout << disk.size();
}

