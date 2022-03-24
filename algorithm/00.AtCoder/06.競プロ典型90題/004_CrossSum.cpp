#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int h, w;
    cin >> h >> w;
    vector<vector<int> > a(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; ++j) {
            cin >> a[i][j];
        }
    }

    vector<int> vertical(h, 0), horizontal(w, 0);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            vertical[i] += a[i][j];
            horizontal[j] += a[i][j];
        }
    }

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cout << vertical[i] + horizontal[j] - a[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}



/**** 2022.3.13 復習 ***/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> a[i][j];
        }
    }

    vector<ll> hor(h, 0), ver(w, 0);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            hor[i] += a[i][j];
            ver[j] += a[i][j];
        }
    }

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cout << hor[i] + ver[j] - a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
