#include <iostream>
#include <vector>

int main() {
  long long time = 0;
  long long coord = 0;
  long long cnt = 0;
  std::cin >> time >> coord >> cnt;

  std::vector<std::vector<double>> lights_list(cnt, std::vector<double> (3));
  double a = 0;
  double b = 0;
  double p = 0;

  for (int i = 0; i < cnt; i++) {
    std::cin >> a >> b >> p;
    lights_list[i][0] = a;
    lights_list[i][1] = b;
    lights_list[i][2] = p;
  }

  double left = -1;
  double right = 1e18;
  double eps = 0.000000001;
  while (left + eps < right) {
    double mid = (left + right) / 2;

    double ans = 0;
    double sum_p = 0;
    double pos = 0;

    for (int i = 1; i <= cnt; i++) {
      ans += (p-pos) / mid;
      pos = p;
      if (ans - (ans / (a + b)) * (a + b) > a) {
        ans += (ans - (ans / (a + b)) * (a + b) - a) * mid;
      }
    }
    if (ans > time) {
      left = mid;
    }
    else {
      right = mid;
    }
    std::cout << mid << ' ' << ans << std::endl;
  }
}