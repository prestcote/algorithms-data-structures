#include <iostream>

int main() {
  long long n = 0;
  std::cin >> n;
  long long* arr = new long long[n];
  long long a = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> a;
    arr[i] = a;
  }
	long long ans = arr[0];
	long long ans_l = 0;
	long long ans_r = 0;
	long long sum = 0;
	long long min_sum = 0;
	long long min_pos = -1;
	for (int r = 0; r < n; ++r) {
		sum += arr[r];

		int cur = sum - min_sum;
		if (cur > ans && min_pos + 1 == r) {
			ans = cur;
			ans_l = min_pos + 1;
			ans_r = r; 
		}

		if (sum < min_sum) {
			min_sum = sum;
			min_pos = r;
		}
	}
	std::cout << ans << ' ' << ans_l << ' ' << ans_r;
}