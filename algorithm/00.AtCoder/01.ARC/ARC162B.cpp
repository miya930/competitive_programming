#include <bits/stdc++.h>
using ll = long long;

int main()
{
	int n;
	std::cin >> n;
	std::vector<int> p(n);
	for (auto &i : p) {
		std::cin >> i;
		i--;
	}
 
	bool flag = true;
	std::vector<std::pair<int, int>> ops;
	for (int i = 0; i < n - 1; i++) {
		if (p[i] == i) continue;
		int j = i;
		while (j < n && p[j] != i) j++;
		assert(j < n);
		if (j == n - 1) {
			if (i + 3 > n) {
				flag = false;
				break;
			}
			ops.emplace_back(n - 1, n - 3);
			int t = p[n - 3];
			p.erase(p.end() - 3);
			p.emplace_back(t);
			j--;
		}
		ops.emplace_back(j + 1, i);
		std::vector<int> sp{p.begin() + j, p.begin() + j + 2};
		p.erase(p.begin() + j, p.begin() + j + 2);
		p.insert(p.begin() + i, sp.begin(), sp.end());
	}
 
	if (!flag || !std::is_sorted(p.begin(), p.end())) {
		std::cout << "No" << std::endl;
	} else {
		std::cout << "Yes" << std::endl
			<< ops.size() << std::endl;
		for (auto [i, j] : ops) {
			std::cout << i << " " << j << std::endl;
		}
	}
}
