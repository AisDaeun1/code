#include <bits/stdc++.h>
int main() {
	std::cin.tie(nullptr)->sync_with_stdio(false);
	std::map<int, int> m;
	int n;
	std::cin >> n;
	for (int x = 0; x < n; x++) {
		using arr = std::array<int, 5>;
		arr a;
		for (auto &i : a) std::cin >> i;
		for (int i = 0; i < 5; i++) {
			for (int j = 1; j <= 9; j++) {
				auto getSum = [] (arr &x) {
					int res = 0, base = 1;
					for (int i = 0; i < 5; i++) {
						res += x[i] * base;
						base *= 10;
					}
					return res;
				};
				arr b(a);
				b[i] = (a[i] + j) % 10;
				m[getSum(b)]++;
				if (i == 0) continue;
				arr c(a);
				c[i - 1] = (a[i - 1] + j) % 10;
				c[i] = (a[i] + j) % 10;
				m[getSum(c)]++;
			}
		}
	}
	int ans = 0;
	for (auto &i : m) 
		if (i.second >= n) ans++;
	std::cout << ans << '\n';
}
