#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main()
{
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> str(h);
    for (int i = 0; i < h; ++i) cin >> str[i];

    vector<vector<int>> vec(h, vector<int>(w, -1));

    int cnt = 1;
    map<int, pair<int,int>> mp;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (str[i][j] == '#') {
                vec[i][j] = cnt;
                mp[cnt] = P(i, j);
                cnt++;
            }
        }
    }

    for (int num = 1; num <= k; num++) {
        int x = mp[num].first;
        int y = mp[num].second;

        int ma_y = y;
        int mi_y = y;
        while (ma_y+1 < w && vec[x][ma_y+1] == -1) {
            ma_y++;
            vec[x][ma_y] = num;
        }
        while (mi_y-1 >= 0 && vec[x][mi_y-1] == -1) {
            mi_y--;
            vec[x][mi_y] = num;
        }

        int ma_x = x;
        int mi_x = x;
        while (ma_x+1 < h) {
            bool flag = true;
            for (int i = mi_y; i <= ma_y; ++i) {
                if (vec[ma_x+1][i] != -1) flag = false;
            }
            if (!flag) break;
            else {
                for (int i = mi_y; i <= ma_y; ++i) {
                    vec[ma_x+1][i] = num;
                }
            }
            ma_x++;
        }

        while (mi_x-1 >= 0) {
            bool flag = true;
            for (int i = mi_y; i <= ma_y; ++i) {
                if (vec[mi_x-1][i] != -1) flag = false; 
            }
            if (!flag) break;
            else {
                for (int i = mi_y; i <= ma_y; ++i) {
                    vec[mi_x-1][i] = num;
                }
            }
            mi_x--;
        }
    }

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
