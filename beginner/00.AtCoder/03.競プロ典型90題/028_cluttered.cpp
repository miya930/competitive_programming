/**
 * ‹£ƒvƒ“TŒ^90–â
 * 028 - Clutterd Paper (š4)
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

    // ‰¡•ûŒü‚Ì—İÏ˜a
    for (int y = 0; y <= MAX; ++y) {
        for (int x = 1; x <= MAX; ++x) {
            tile[y][x] += tile[y][x-1];
        }
    }

    // c•ûŒü‚Ì—İÏ˜a
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
