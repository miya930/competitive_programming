#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; i++) cin >> p[i];
        vector<int> v(n);
        for (int i = 0; i < n; i++) v[p[i]-1] = i;

        int ans = 0;
        for (int i = 0; i < n; i++) {
            bool isok = true;
            for (int j = 0; j < p[i]-1; j++) {
                if (v[j] > i) isok = false;
            }
            if (isok) ans++;
        }

        cout << ans << endl;
    }

    return 0;
}
