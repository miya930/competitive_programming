#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> s(m), c(m);
	for (int i = 0; i < m; ++i) cin >> s[i] >> c[i], s[i]--;

	for (int ans = 0; ans < 1000; ++ans) {
		string str = to_string(ans);
		if (str.length() != n) continue;

		bool ok = true;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (j == s[i] && (str[j] - '0') != c[i]) ok = false;
			}
		}
		if (ok) {
			cout << ans << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}
