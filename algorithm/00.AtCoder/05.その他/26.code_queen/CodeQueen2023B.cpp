#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool field[5040][5040];
int dx[] = {0, 1, 0, -1, -1, -1, 1, 1};
int dy[] = {1, 0, -1, 0, -1, 1, -1, 1};

int main()
{
    int n;
    cin >> n;
    vector<int> r(n-1), c(n-1);
    map<pair<int,int>, int> mp;
    for (int i = 0; i < n-1; i++) {
        cin >> r[i] >> c[i];
        r[i]--; c[i]--;
        mp[make_pair(r[i], c[i])]++;
    }

    for (int i = 0; i < n-1; i++) {
        field[r[i]][c[i]] = true;
        for (int j = 0; j < 8; j++) {
            int nx = r[i];
            int ny = c[i];

            while(1) {
                nx += dx[j];
                ny += dy[j];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) break;
                field[nx][ny] = true;
            }
        }
    }

    vector<pair<int,int>> pa;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!field[i][j]) pa.push_back(make_pair(i, j));
        }
    }

    for (int i = 0; i < pa.size(); i++) {
        int vx = pa[i].first;
        int vy = pa[i].second;

        bool ok = true;
        for (int j = 0; j < 8; j++) {
            int nx = vx;
            int ny = vy;

            while(1) {
                nx += dx[j];
                ny += dy[j];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
                    break;
                }
                if (mp.count(make_pair(nx, ny))) {
                    ok = false;
                    break;
                }
            }
        }

        if (ok) {
            cout << vx + 1 << " " << vy + 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
}
