#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int ans = 0;

    vector<vector<pair<int, int> > > vec(n);
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        for (int j = 0; j < a; ++j) {
            int x, y;
            cin >> x >> y;
            x--; y;
            vec[i].push_back({ x, y });
        }
    }

    for (int bit = 0; bit < 1 << n; ++bit) {
        bool flag = true;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (bit >> i & 1) {
                cnt++;
                int siz = vec[i].size();
                for (int j = 0; j < siz; ++j) {
                    int x = vec[i][j].first;
                    int y = vec[i][j].second;
                    if (y == 1 && !(bit >> x & 1)) flag = false;
                    if (y == 0 && bit >> x & 1) flag = false;
                }
            }
        }
        if (flag) ans = max(ans, cnt);
    }

    cout << ans << endl;
}
