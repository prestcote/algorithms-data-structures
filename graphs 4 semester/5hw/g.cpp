#include <iostream>
#include <vector>

int main() {
	int n = 0;
	std::cin >> n;
	char a;
	std::vector<std::vector<int>> g(n, std::vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> a;
			if (a == '1') {
				g[i][j] = 1;
			}
			else {
				g[i][j] = 0;
			}
		}
		//std::cout << i << '\n' ;
	}
	//std::cout <<"next step/n" ;
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (g[i][k] == 1 && g[k][j] == 1) {
					g[i][j] = 1;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << g[i][j];
		}
		std::cout << '\n';
	}
	return 0;
}