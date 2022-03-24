/**
 * ���v���T�^90��
 * 028 - Clutterd Paper (��4)
 * link : https://atcoder.jp/contests/typical90/tasks/typical90_ab
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
const int MAX = 1000;

int main()
{
    int n;
    cin >> n;
    vector<vector<long long> > tile(1010, vector<long long>(1010,0));
    
    for (int i = 0; i < n; ++i) {
        int lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;
        tile[ly][lx]++;
        tile[ry][lx]--;
        tile[ly][rx]--;
        tile[ry][rx]++;
    }

    // �������̗ݐϘa
    for (int y = 0; y <= MAX; ++y) {
        for (int x = 1; x <= MAX; ++x) {
            tile[y][x] += tile[y][x-1];
        }
    }

    // �c�����̗ݐϘa
    for (int y = 1; y <= MAX; ++y) {
        for (int x = 0; x <= MAX; ++x) {
            tile[y][x] += tile[y-1][x];
        }
    }
    
    map<int, int> mp;
    for (int y = 0; y <= MAX; ++y) {
        for (int x = 0; x <= MAX; ++x) {
            mp[tile[y][x]]++;
        }
    }
    
    for (int k = 1; k <= n; ++k) cout << mp[k] << endl;
}

/*** 2022.3.13 ***/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int field[1020][1020];
vector<int> ans(100100);

int main()
{
    int n;
    cin >> n;
    vector<pair<int,int>> lpa(n), rpa(n);
    for (int i = 0; i < n; ++i) {
        cin >> lpa[i].first >> lpa[i].second >> rpa[i].first >> rpa[i].second;
    }

    for (int i = 0; i < n; ++i) {
        field[lpa[i].first][lpa[i].second]++;
        field[lpa[i].first][rpa[i].second]--;
        field[rpa[i].first][lpa[i].second]--;
        field[rpa[i].first][rpa[i].second]++;
    }

    for (int i = 1; i < 1000; ++i) {
        for (int j = 0; j < 1000; ++j) {
            field[i][j] += field[i-1][j];
        }
    }

    for (int i = 0; i < 1000; ++i) {
        for (int j = 1; j < 1000; ++j) {
            field[i][j] += field[i][j-1];
        }
    }

    for (int i = 0; i < 1000; ++i) {
        for (int j = 0; j < 1000; ++j) {
            ans[field[i][j]]++;
        }
    }

    for (int i = 1; i <= n; ++i) cout << ans[i] << endl;

    return 0;
}
