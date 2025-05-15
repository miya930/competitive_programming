#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> c(n), d(m);
    vector<int> p(m+1);
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 0; i < m; i++) cin >> d[i];
    for (int i = 0; i < m+1; i++) cin >> p[i];

    map<string, int> mp;
    for (int i = 0; i < m; i++) {
        mp[d[i]] = p[i+1];
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (mp.count(c[i])) {
            sum += mp[c[i]];
        } else {
            sum += p[0];
        }
    }
    cout << sum << endl;

    return 0;
}
