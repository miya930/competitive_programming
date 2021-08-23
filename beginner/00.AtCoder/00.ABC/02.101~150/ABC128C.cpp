#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> k(m), p(m);
    vector<vector<int> > S(10);

    for (int i = 0; i < m; ++i) {
        int k; cin >> k;
        for (int j = 0; j < k; ++j) {
            int s; cin >> s; s--;
            S[i].push_back(s);
        }
    }

    for (int i = 0; i < m; ++i) cin >> p[i];

    int ans = 0;
    for (int bits = 0; bits < (1 << n); bits++) {
        int ok = 0;
        for (int i = 0; i < m; ++i) {
            int cnt = 0;
            for (auto a : S[i]) {
                if (bits & (1 << a)) cnt++;
            }
            if (cnt % 2 == p[i]) ok++;
        }
        if (ok == m) ans++;
    }
    cout << ans << endl;
}

/***
 * 2021.8.22 復習
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> k(m), p(m);
    vector<vector<int> > s(m);
    for (int i = 0; i < m; ++i) {
        cin >> k[i];
        for (int j = 0; j < k[i]; ++j) {
            int a; cin >> a;
            a--;
            s[i].push_back(a);
        }
    }

    for (int i = 0; i < m; ++i) cin >> p[i];

    int ans = 0;
    for (int bit = 0; bit < 1<<n; ++bit) {
        vector<int> vec(m, 0);
        for (int i = 0; i < n; ++i) {
            if (bit>>i & 1) {
                for (int j = 0; j < m; ++j) {
                    for (int l = 0; l < k[j]; ++l) {
                        if (s[j][l] == i) vec[j]++;
                    }
                }
            }
        }
        bool ok = true;
        for (int i = 0; i < m; ++i) {
            if (p[i] != (vec[i]%2)) ok = false; 
        }
        if (ok) ans++;
    }

    cout << ans << endl;
    return 0;

}
