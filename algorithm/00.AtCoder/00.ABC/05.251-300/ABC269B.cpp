#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1001001001;

int main()
{
    string str[10];
    for (int i = 0; i < 10; ++i) cin >> str[i];

    int mi_x = inf, mi_y = inf, ma_x = 0, ma_y = 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (str[i][j] == '#') {
                mi_x = min(mi_x, i);
                mi_y = min(mi_y, j);
                ma_x = max(ma_x, i);
                ma_y = max(ma_y, j);
            }
        }
    }

    cout << mi_x+1 << " " << ma_x+1 << endl;
    cout << mi_y+1 << " " << ma_y+1 << endl;

    return 0;
}
