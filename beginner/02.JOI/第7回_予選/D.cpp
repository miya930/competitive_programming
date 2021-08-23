// 第7回日本情報オリンピック予選 (過去問)
// https://atcoder.jp/contests/joi2008yo/submissions/me
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int m, n;
    cin >> m;
    vector<pair<int, int> > v(m);
    rep(i, m) cin >> v[i].first >> v[i].second;
    cin >> n;
    vector<pair<int, int> > pos(n);
    rep(i, n) {
        cin >> pos[i].first >> pos[i].second;
    }

    int sx = v[0].first, sy = v[0].second;

    int ax = 0, ay = 0;
    for (int i = 0; i < n; ++i) {
        bool flag = true;
        int dx = pos[i].first - sx;
        int dy = pos[i].second - sy;

        for (int j = 0; j < m; ++j) {
            bool exist = false;
            for (int k = 0; k < n; ++k) {
                int nx = pos[k].first - dx;
                int ny = pos[k].second - dy;
                if (nx == v[j].first && ny == v[j].second) exist = true;
            }
            if (!exist) {
                flag = false;
                break;
            }
        }

        if (flag) {
            ax = dx; ay = dy;
            break;
        }
    }

    cout << ax << " " << ay << endl;
}
