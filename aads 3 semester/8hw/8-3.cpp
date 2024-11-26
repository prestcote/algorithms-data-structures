#include <iostream>
#include <vector>
#include <random>
#include <vector>
#include <algorithm>


std::mt19937_64 rd(time(0));

bool p(double t, int df) {
  return std::exp(df / t) > ((double)rd() / UINT64_MAX);
}

int delta(std::vector<int> people, int per_person) {
  int count = 0;
  for (int i = 0; i < people.size(); i++) {
    count += std::abs(people[i] - per_person);
  }
  return count;
}
//1
int main() {
  int n = 0;
  int k = 0;
  std::cin >> n >> k;
  std::vector<int> prizes(n, 0);
  std::vector<int> people(k, 0);
  int sum = 0;

  if (k == 1) {
    for (int i = 0; i < n; i++) {
      std::cout << i + 1 << ' ';
    }
    return 0;
  }

  for (int i = 0; i < n / k; i++) {
    for (int j = 0; j < k; j++) {
      //std::cout << j << ' ';
      prizes[i * k + j] = j;
    }
  }
  //std::cout << std::endl;
  for (int i = 0; i < n; i++) {
    people[prizes[i]] += i + 1;
    sum += i + 1;
    //std::cout << prizes[i] << ' ';
  }
  if (sum % k != 0) {
    std::cout << 0;
    return 0;
  }

  //std::cout << '\n';
  int per_person = sum / k;

  int cnt = 0;
  double t = 10000;
  while (t > 0.00001) {
    //std::cout << "HEHEHAHA";
    int index1 = rd() % n;
    int index2 = rd() % n;
    int firstPerson = prizes[index1];
    int secondPerson = prizes[index2];
    cnt += 1;
    if (firstPerson != secondPerson) {
      t = t * 0.999995;

      int cur = delta(people, per_person);
      if (cur == 0) {
        for (int i = 0; i < k; i++) {
          for (int j = 0; j < n; j++) {
            if (prizes[j] == i) {
              std::cout << j + 1 << ' ';
            }
          }
          std::cout << std::endl;
        }
        //std::cout << '\n' << cnt;
        return 0;
      }
      people[firstPerson] += (index2 - index1);
      people[secondPerson] += (index1 - index2);
      int fut = delta(people, per_person);

      if ((fut < cur) || p(t, -std::abs(fut - cur))) {
        prizes[index1] = secondPerson;
        prizes[index2] = firstPerson;
      }
      else {
        people[firstPerson] += (index1 - index2);
        people[secondPerson] += (index2 - index1);
      }
      if (fut == 0) {
        for (int i = 0; i < k; i++) {
          for (int j = 0; j < n; j++) {
            if (prizes[j] == i) {
              std::cout << j + 1 << ' ';
            }
          }
          std::cout << std::endl;
        }
        //std::cout << '\n' << cnt;
        return 0;
      }
    }

  }
  if (delta(people, per_person) != 0) {
    std::cout << 0;// << " yee haw";
  }
  //std::cout << '\n' << cnt;
  return 0;
}