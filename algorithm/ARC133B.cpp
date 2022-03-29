#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
vector<int> v, f;

int main()
{
    cin >> n;
    vector<int> p(n+1), q(n+1);
    vector<int> pos(n+10, 0);
    f.assign(n+10, 1);
    for (int i = 1; i <= n; ++i) cin >> p[i];
    for (int i = 1; i <= n; ++i) {
        cin >> q[i];
        pos[q[i]] = i;
    }

    for (int i = 1; i <= n; ++i) {
        v.clear();
        for (int j = p[i]; j <= n; j += p[i]) v.push_back(-pos[j]);
        sort(v.begin(), v.end());
        for (auto j : v) {
            j = -j;
            int k = lower_bound(f.begin()+1, f.end()+n, j) - f.begin();
            f[k] = j;
        }
    }
    
    for (int i = 1;;++i) {
        if (f[i] > n) {
            cout << i-1;
            return 0;
        }
    }

    return 0;
}
