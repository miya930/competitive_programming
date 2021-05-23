/**
 * ��������
 * �����̊g���F���
 * URL�Fhttps://imoz.jp/algorithms/imos_method.html
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
    // �������ւ̗ݐϘa
    for (int y = 0; y < h; y++) {
        for (int x = 1; x < w; x++) {
            tiles[y][x] += tiles[y][x-1];
        }
    }
    // �c�����ւ̗ݐϘa
    for (int y = 1; y < h; y++) {
        for (int x = 0; x < w; x++) {
            tiles[y][x] += tiles[y-1][x];
        }
    }
    int res = 0;
    // �ő�l�����߂�
    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
            res = max(res, tiles[y][x]);
        }
    }
}
