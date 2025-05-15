#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, m, h, k;
    cin >> n >> m >> h >> k;
    string s;
    cin >> s;
    vector<int> x(m), y(m);
    map<pair<int,int>, bool> item;
    for (int i = 0; i < m; i++) {
        cin >> x[i] >> y[i];
        item[make_pair(x[i], y[i])] = true;
    }
    map<char, pair<int,int>> mp;
    mp['R'].first = 1;
    mp['R'].second = 0;
    mp['L'].first = -1;
    mp['L'].second = 0;
    mp['U'].first = 0;
    mp['U'].second = 1;
    mp['D'].first = 0;
    mp['D'].second = -1;

    int curx = 0, cury = 0;
    for (int i = 0; i < n; i++) {
        int nx = curx + mp[s[i]].first;
        int ny = cury + mp[s[i]].second;
        h--;
        if (h < 0) {
            cout << "No" << endl;
            return 0;
        }

        if (item[make_pair(nx, ny)]) {
            if (h < k) {
                h = k;
                item[make_pair(nx, ny)] = false;
            }
        }
        curx = nx;
        cury = ny;
    }
    cout << "Yes" << endl;
    return 0;
}
