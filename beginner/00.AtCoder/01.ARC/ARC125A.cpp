#include <iostream>
#include <vector>
#include <algorithm>
using namespace  std;
const int inf = 1000000007;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> s(n), t(m);
    for (int i = 0; i < n; ++i) cin >> s[i];
    for (int j = 0; j < m; ++j) cin >> t[j];

    int a = 0, b = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 1)  a = a | 1<<1;
        else a = a | 1<<0;
    }
    for (int i = 0; i < m; ++i) {
        if (t[i] == 1) b = b | 1<<1;
        else b = b | 1<<0;
    }
    
    bool ng = false;
    for (int i = 0; i < 2; ++i) {
        if (((a>>i & 1) == 0) && ((b>>i & 1) == 1)) ng = true;   
    }
    if (ng) {
        cout << -1 << endl;
        return 0;
    }

    // a0から一番近い0, 1を記録する。
    int nz = inf;
    int no = inf;

    for (int i = 0; i < n; ++i) {
        if (s[i] == 0) {
            nz = min(nz, i);
            if (nz > n - i) nz = i;
        } else {
            no = min(no, i);
            if (no > n - i) no = i;
        }
    }

    long long ans = 0;
    int now = s[0];
    bool ini = true;
    for (int i = 0; i < m; ++i) {
        if (t[i] != now) {
            if (ini) {
                if (t[i] == 0) {
                    ans += (min(nz, n-nz)+1);
                    now = t[i];
                    ini = false;
                } else {
                    ans += (min(no, n-no)+1);
                    now = t[i];
                    ini = false;
                }
            } else {
                ans += 2;
                now = t[i];
            }
        } else {
            ans++;
        }
    }
    cout << ans << endl;
}
