#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int h, w;
    cin >> h >> w;

    vector<string> c(h);
    for (int i = 0; i < h; i++) cin >> c[i];

    vector<vector<int>> ro(h, vector<int>(26, 0)), co(w, vector<int>(26, 0));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int idx = c[i][j] - 'a';
            ro[i][idx]++;
        }
    }
    for (int j = 0; j < w; j++) {
        for (int i = 0; i < h; i++) {
            int idx = c[i][j] - 'a';
            co[j][idx]++;
        }
    }
    int cr = h, cc = w;
    queue<pair<int,int>> rque, cque;
    while(1) {
        bool rno = false, cno = false;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < 26; j++) {
                if (ro[i][j] == cc && cc > 1) {
                    rque.push(make_pair(j, i));
                    ro[i][j] = 0;
                }
            }
        }

        for (int i = 0; i < w; i++) {
            for (int j = 0; j < 26; j++) {
                if (co[i][j] == cr && cr > 1) {
                    cque.push(make_pair(j, i));
                    co[i][j] = 0;
                }
            }
        }

        if (!rque.empty()) {
            while(!rque.empty()) {
                int idx = rque.front().first;
                int row = rque.front().second;
                rque.pop();
                for (int i = 0; i < w; i++) {
                    if (co[i][idx] == 0) continue;
                    co[i][idx]--;
                }
                cr--;
                ro[row][idx] = 0;
            }
        } else {
            rno = true;
        }

        if (!cque.empty()) {
            while(!cque.empty()) {
                int idx = cque.front().first;
                int col = cque.front().second;
                cque.pop();
                for (int i = 0; i < h; i++) {
                    if (ro[i][idx] == 0) continue;
                    ro[i][idx]--;
                }
                cc--;
                co[col][idx] = 0;
            }
        } else {
            cno = true;
        }

        if (rno && cno) {
            break;
        }
    }

    cout << cc * cr << endl;

}
