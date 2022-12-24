#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) cin >> p[i];

    vector<int> v(n), vt(n), vec = p;
    for (int i = 0; i < n; ++i) vt[i] = i;
    sort(vec.begin(), vec.end());

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (p[i] == vec[j]) {
                v[i] = j;
            }
        }
    }

    int cnt = 0;
    vector<int> ans(n);
    do {
        if (cnt > 1) {
            break;
        } else if (cnt == 1) {
            for (int i = 0; i < n; ++i) {
                ans[i] = vec[v[i]];
            }
        }

        cnt++;

    } while(prev_permutation(v.begin(), v.end()));

    for (int i = 0; i < n; ++i) cout << ans[i] << " ";
    cout << endl;

    return 0;
}
