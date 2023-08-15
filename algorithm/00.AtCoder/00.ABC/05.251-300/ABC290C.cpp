#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }

    int ma = 0;
    int cnt = 0;
    for (auto x : mp) {
        int s = x.first;
        cnt++;

        if (ma == s && cnt <= k) {
            ma++;
        }

    }
    cout << ma << endl;

    return 0;
}
