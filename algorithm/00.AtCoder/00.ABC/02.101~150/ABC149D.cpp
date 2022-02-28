#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string grep[101010];

int main()
{
    int n, k;
    int R, S, P;
    string t;
    cin >> n >> k >> R >> S >> P >> t;
    for (int i = 0; i < n; ++i) grep[i%k] += t[i];

    int ans = 0;
    for (int i = 0; i < k; ++i) {
        int r = 0, s = 0, p = 0;
        if (grep[i][0] == 'r') p = P;
        if (grep[i][0] == 's') r = R;
        if (grep[i][0] == 'p') s = S;

        for (int j = 1; j < (int)grep[i].size(); ++j) {
            int rr = max(s, p);
            int ss = max(r, p);
            int pp = max(r, s);

            if (grep[i][j] == 'r') pp += P;
            if (grep[i][j] == 's') rr += R;
            if (grep[i][j] == 'p') ss += S;

            r = rr;
            s = ss;
            p = pp;
        }

        ans += max({r,s,p});
    }

    cout << ans << endl;

    return 0;
}
