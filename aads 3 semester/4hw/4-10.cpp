#include <iostream>
#include <vector>

int mins = 100000000;

void rec(int stone, int one, int two, std::vector<int>vec) {
  if (stone == vec.size() - 1) {
    if (mins > std::abs(one - two)) {
      mins = std::abs(one - two);
    }
  }
  else {
    rec(stone + 1, one + vec[stone], two, vec);
    rec(stone + 1, one, two + vec[stone], vec);
  }
}

int main() {
  int n = 0;
  std::cin >> n;
  int a = 0;
  std::vector <int> stones;
  for (int i = 0; i < n; i++) {
    std::cin >> a;
    stones.push_back(a);
  }
  rec(0, 0, 0, stones);
  std::cout << mins;
}