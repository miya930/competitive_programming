#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    cin >> n;

    ll k = -1;
    for (ll i = 1; i <= n+5; i++) {
        if (n == i*(i-1)/2) {
            k = i;
            break;
        }
    }
    if (k == -1) {
        cout << "No" << endl;
        return 0;
    }

    vector<vector<int>> ans(k);
    int cnt = 1;
    for (int i = 0; i < k; i++) {
        for (int j = i+1; j < k; j++) {
            ans[i].push_back(cnt);
            ans[j].push_back(cnt);
            cnt++;
        }
    }

    cout << "Yes" << endl;
    cout << k << endl;
    for (int i = 0; i < k; i++) {
        cout << ans[i].size() << " ";
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
