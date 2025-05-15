#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, D;
    cin >> n >> D;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];

    int ans = 0;
    int cur = 0;
    for (int d = 0; d < D; d++) {
        bool isok = true;
        for (int i = 0; i < n; i++) {
            if (s[i][d] != 'o') {
                isok = false;
            }
        }

        if (isok) {
            cur++;
            ans = max(ans, cur);
        } else {
            ans = max(ans, cur);
            cur = 0;
        }

    }
    cout << ans << endl;
    return 0;
}
