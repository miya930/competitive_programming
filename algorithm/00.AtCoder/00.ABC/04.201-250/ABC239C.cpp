#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};

int main()
{
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    bool ans = false;

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (i == j) continue;
            int nx1 = x1 + dx[i];
            int ny1 = y1 + dy[i];
            int nx2 = x2 + dx[j];
            int ny2 = y2 + dy[j];

            if (nx1 == nx2 && ny1 == ny2) ans = true;
        }
    }

    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;    

    return 0;
}
