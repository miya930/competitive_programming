#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main()
{
    ll n, m;
    cin >> n >> m;

    P ans = {0, 0};

    for(int d = 1; d <= 9; d++) {
        ll x = 0;
        for (int i = 1; i <= n; i++) {
            x = (10 * x + d) % m;
            if (x == 0) ans = max(ans, P({i, d}));
        }
    }

    int i = ans.first;
    int d = ans.second;
    if (i == 0) {
        cout << -1 << endl;
    } else {
        string s(i, '0' + d);
        cout << s << endl;
    }

    return 0;
}
