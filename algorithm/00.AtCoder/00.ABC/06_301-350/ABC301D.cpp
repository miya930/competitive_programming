#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string s;
    ll n;
    cin >> s >> n;

    int m = s.size();
    ll cur = 0;
    for (int i = 0; i < m; i++) {
        if (s[i] == '1') {
            cur += (1LL << (m-i-1));
        }
    }
    if (cur > n) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 0; i < m; i++) {
        ll tmp = cur + (1LL << (m-i-1));
        if (tmp <= n && s[i] == '?') {
            cur = tmp;
            s[i] = '1';
        } else {
            s[i] = '0';
        }
    }
    cout << cur << endl;
    return 0;
}
