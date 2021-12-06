#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> d(k);
    map<int, int> mp;
    for (int i = 0; i < k; ++i) {
        cin >> d[i];
        mp[d[i]]++;
    }

    int ans = 0;
    for (int i = n; i <= 100000; ++i) {
        bool ok = true;
        int j = i;
        while (j > 0) {
            int tmp = j % 10;
            if (mp[tmp]) ok = false;
            j /= 10;
        }
        if (ok) {
            ans = i;
            break;
        }
    }
    
    cout << ans << endl;

    return 0;
}
