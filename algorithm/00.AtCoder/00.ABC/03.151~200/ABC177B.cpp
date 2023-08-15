#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int inf = 1001001001;

int main()
{
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();

    int ans = inf;
    for (int i = 0; i <= n-m; i++) {
        int cnt = 0;
        for (int j = 0; j < m; j++) {
            if (s[i+j] != t[j]) cnt++;
        }

        ans = min(ans, cnt);
    }

    cout << ans << endl;
    return 0;
}
