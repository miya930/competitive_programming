#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    int ans1 = 0, ans2 = 0;
    map<int,int> mp1;
    map<int,int> mpa, mpb;
    for (int i = 0; i < n; ++i) {
        if (a[i] == b[i]) {
            ans1++;
            mp1[a[i]]++;
        }
    }

    for (int i = 0; i < n; ++i) {
        mpa[a[i]]++;
        mpb[b[i]]++;
    }

    for (auto x : a) {
        int s = mpa[x];
        int t = mpb[x];
        if (s == 0 || t == 0) continue; 
        ans2 = ans2 + (s*t - mp1[x]);
    }

    cout << ans1 << endl;
    cout << ans2 << endl;

    return 0;
}
