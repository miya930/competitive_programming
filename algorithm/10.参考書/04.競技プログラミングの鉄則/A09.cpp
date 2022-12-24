#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int h, w, n;
    cin >> h >> w >> n;

    vector<int> a(n), b(n), c(n), d(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        a[i]--;
        b[i]--;
        c[i]--;
        d[i]--; 
    }

    vector<vector<int>> field(h, vector<int>(w, 0));

    for (int i = 0; i < n; ++i) {
        field[a[i]][b[i]]++;
        if (d[i]+1 < w) field[a[i]][d[i]+1]--;
        if (c[i]+1 < h) field[c[i]+1][b[i]]--;
        if (c[i]+1 < h && d[i]+1 < w) field[c[i]+1][d[i]+1]++;
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w-1; j++) {
            field[i][j+1] += field[i][j];
        }
    }

    for (int j = 0; j < w; j++) {
        for (int i = 0; i < h-1; i++) {
            field[i+1][j] += field[i][j];
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << field[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
