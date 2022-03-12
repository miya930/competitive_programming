#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<class T> T gcd(T n, T m) {
    if (m == 0) return n;
    else return gcd(m, n%m);
}

template<class T> T lcm(T n, T m) {
    return n / gcd(n, m) * m;
}

map<int, char> ans;

int main()
{
    ll n, m;
    string s, t;
    cin >> n >> m >> s >> t;

    if (s[0] != t[0]) {
        cout << -1 << endl;
        return 0;
    }

    ll l = lcm(n, m);

    int ssi = s.size();
    int tsi = t.size();
    for (int i = 1; i < ssi; ++i) {
        int idx = i*l/n+1;
        ans[idx] = s[i];
    }

    bool flag = true;
    for (int i = 1; i < tsi; ++i) {
        int idx = i*l/m+1;
        
        if (ans[idx] == 0) ans[idx] = t[i];
        else if (ans[idx] != t[i]) flag = false;
        
    }

    if (!flag) cout << -1 << endl;
    else cout << l << endl; 

    return 0;
}
