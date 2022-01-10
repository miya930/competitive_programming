#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string s;
    cin >> s;

    int n = s.size();
    vector<ll> left(n+1, 0), right(n+1, 0);
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (s[i-1] == '<') cnt++;
        else cnt = 0;
        left[i] = cnt;
    }
    cnt = 0;
    for (int i = n-1; i >= 0; --i) {
        if (s[i] == '>') cnt++;
        else cnt= 0;
        right[i] = cnt;
    }
    
    vector<ll> a(n+1,0);
    ll ans = 0;
    for (int i = 0; i < n+1; ++i) {
        a[i] = max(right[i],left[i]);
        ans += a[i];
    }

    cout << ans << endl;
    return 0;
}
