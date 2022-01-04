#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> cnt(n, 0);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        if (a < b) cnt[b]++;
        else cnt[a]++;
    }    

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (cnt[i] == 1) ans++;
    } 

    cout << ans << endl;
    return 0;
}
