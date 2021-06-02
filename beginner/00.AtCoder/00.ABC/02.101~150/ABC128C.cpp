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
