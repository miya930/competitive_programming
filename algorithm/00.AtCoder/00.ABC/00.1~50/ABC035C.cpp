#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> cnt(n+1, 0);

    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        l--; r--;

        cnt[l]++;
        cnt[r+1]--;
    }

    for (int i = 0; i < n; ++i) {
        cnt[i+1] += cnt[i];
    }

    string ans = "";
    for (int i =0; i < n; ++i) {
        if (cnt[i]%2 == 0) ans += '0';
        else ans += '1'; 
    }
    cout << ans << endl;
    return 0;
}
