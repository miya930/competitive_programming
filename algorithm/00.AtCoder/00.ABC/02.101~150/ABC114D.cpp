#include <bits/stdc++.h>
using namespace std;
using ll = long long;

map<int,int> func(int n) {
    map<int,int> mp;
    mp[1]++;
    for (int j = 2; j <= n; ++j) {
        int t = j;
        for (int i = 2; i*i <= j; ++i) {
            if (t%i != 0) continue;
            int ex = 0;
            while(t%i == 0) {
                ex++;
                t /= i;
            }
            mp[i] += ex;
        }
        if (t != 1) mp[t]++;
    }
    return mp;
}

int main()
{
    int n;
    cin >> n;

    map<int,int> v = func(n);
    int ans = 0;

    // 75
    for (int a = 2; a <= n; ++a) {
        if (74 <= v[a]) ans++;
    }

    // 15*5
    for (int a = 2; a <= n; ++a) {
        for (int b = 2; b <= n; ++b) {
            if (a != b && 14 <= v[a] && 4 <= v[b]) ans++;
        }
    }

    // 3*25
    for (int a = 2; a <= n; ++a) {
        for (int b = 2; b <= n; ++b) {
            if (a != b && 2 <= v[a] && 24 <= v[b]) ans++;
        }
    }

    // 3*5*5
    for (int a = 2; a <= n; ++a) {
        for (int b = 2; b <= n; ++b) {
            for (int c = b+1; c <= n; ++c) {
                if (a != b && a != c && 2 <= v[a] && 4 <= v[b] && 4 <= v[c]) ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
