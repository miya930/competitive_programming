/**
 * Ç¢Ç‡Ç∑å§
 * éüå≥ÇÃägí£ÅFó·ëË
 * URLÅFhttps://imoz.jp/algorithms/imos_method.html
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int h, w, n;
    cin >> h >> w >> n;

    vector<vector<int> > tiles(h, vector<int>(w, 0));
    for (int i = 0; i < n; ++i) {
        tiles[c[i]][a[i]]++;
        tiles[c[i]][b[i]]--;
        tiles[d[i]][a[i]]--;
        tiles[d[i]][b[i]]++;
    }
    // â°ï˚å¸Ç÷ÇÃó›êœòa
    for (int y = 0; y < h; y++) {
        for (int x = 1; x < w; x++) {
            tiles[y][x] += tiles[y][x-1];
        }
    }
    // ècï˚å¸Ç÷ÇÃó›êœòa
    for (int y = 1; y < h; y++) {
        for (int x = 0; x < w; x++) {
            tiles[y][x] += tiles[y-1][x];
        }
    }
    int res = 0;
    // ç≈ëÂílÇãÅÇﬂÇÈ
    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
            res = max(res, tiles[y][x]);
        }
    }
}
