#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main()
{
    int n;
    cin >> n;
    vector<string> in(n);
    vector<vector<int>> a(n, vector<int>(n)), b(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        cin >> in[i];
        for (int j = 0; j < n; j++) {
            a[i][j] = in[i][j] - '0';
            b[i][j] = a[i][j];
        }
    }

    int curx = 0, cury = 0;
    int idx = 0;
    while(1) {
        if ((curx == n-1 && cury == 0) ||
            (curx == n-1 && cury == n-1) ||
            (curx == 0 && cury == n-1) ) {
                idx++;
        } else if (idx == 3 && (curx == 0 && cury == 0)) {
            break;
        }

        int nx = curx + dx[idx];
        int ny = cury + dy[idx];
        b[ny][nx] = a[cury][curx];

        curx = nx;
        cury = ny;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << b[i][j];
        cout << endl;
    }

    return 0;
}
