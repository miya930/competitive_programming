#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<class T> T gcd(T n, T m) {
    if (m == 0) return n;
    else return gcd(m, n%m);
}

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int ma = 0;
    vector<int> lgcd(n+1, 0), rgcd(n+1, 0);

    for (int i = 0; i < n; ++i) lgcd[i+1] = gcd(lgcd[i], a[i]);
    for (int i = n-1; i >= 0; --i) rgcd[i] = gcd(rgcd[i+1], a[i]);

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int g = 0;
        if (i > 0) g = gcd(g, lgcd[i]);
        g = gcd(g, rgcd[i+1]);
        ans = max(ans, g);
    }

    cout << ans << endl;
    return 0;
}
