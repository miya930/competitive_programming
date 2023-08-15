#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> a[i][j];
        }
    }

    vector<string> s;
    for (int i = 0; i < h; i++) {
        string tmp = "";
        for (int j = 0; j < w; j++) {
            if (a[i][j] == 0) tmp.push_back('.');
            else tmp.push_back(a[i][j] + 'A' - 1);
        }
        cout << tmp << endl;
    }

    return 0;
}
