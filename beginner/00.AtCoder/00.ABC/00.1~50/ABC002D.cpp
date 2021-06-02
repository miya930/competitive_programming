#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int main()
{
    bool con[15][15] = {};
    int n, m, x, y;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        con[x-1][y-1] = con[y-1][x-1] = true;
    } 

    int ans = 0;
    for (int S = 1 << n; --S; ) {
        int t = bitset<32>(S).count();
        if (t <= ans) { continue; }

        bool ok = true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (S >> i & S >> j & 1 && !con[i][j]) {
                    ok = false;
                }
            }
        }
        if(ok) { ans = t; }
    }
    cout << ans << endl;
}
