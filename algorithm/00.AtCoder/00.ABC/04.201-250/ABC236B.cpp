#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> a(4*n);
    for(int i = 0; i < 4*n-1; ++i) cin >> a[i];
    vector<int> cnt(4*n, 0);
    for (int i = 0; i < 4*n-1; ++i) {
        a[i]--;
        cnt[a[i]]++;
    }

    int ans = 0;
    for (int i = 0; i < 4*n-1; ++i) {
        if (cnt[a[i]] == 3) ans = a[i];
    }

    cout << ans+1 << endl;
    return 0;
}
