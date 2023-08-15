#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, l;
    cin >> n >> l;
    vector<int> a(n);
    map<int,int> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }

    int cur = 1;
    bool ng = false;
    for (int i = 0; i < n; i++) {
        cur += a[i];
        mp[a[i]]--;

        if (cur > l+1) {
            ng = true;
            break;
        }

        if (mp[2] == 0) break;
        cur++;
    }

    if (!ng) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
