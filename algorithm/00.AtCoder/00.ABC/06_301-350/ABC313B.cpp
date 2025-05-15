#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> s(n, -1);
    vector<int> in(n, 0), out(n, 0);
    vector<bool> seen(n, false);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        in[a]++;
        out[b]++;
        seen[a] = true;
        seen[b] = true;
    }

    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if(out[i] == 0) {
            cnt++;
            ans = i;
        }
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
        if (!seen[i]) ok = false;
    }

    if (cnt > 1 || !ok) cout << -1 << endl;
    else cout << ans+1 << endl;

    return 0;
}
