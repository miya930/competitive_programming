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



/***
 * 
 * 2021.8.25 復習
 * 
 * 
 * 
 */


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool rel[13][13];

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> x(m), y(m);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        rel[x][y] = true;
        rel[y][x] = true;
    }

    int ans = 0;
    for (int bit = 0; bit < 1<<n; ++bit) {
        vector<int> vec;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (bit>>i & 1) {
                vec.push_back(i);
                cnt++;
            }
        }

        bool ok = true;
        for (int i = 0; i < vec.size(); ++i) {
            for (int j = 0; j < vec.size(); ++j) {
                if (i == j) continue;
                if (!rel[vec[i]][vec[j]]) ok = false;

            }
        }
        if (ok) ans = max(ans, cnt);
    }

    cout << ans << endl;
    return 0;
}
