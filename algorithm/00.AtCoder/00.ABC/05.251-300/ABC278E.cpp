#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int H, W, n, h, w;
    cin >> H >> W >> n >> h >> w;
    vector<vector<int>> a(H+1, vector<int>(W+1));
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            cin >> a[i][j];
        }
    }

    map<int, int> mp;
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            int tmp = a[i][j];
            mp[tmp]++;
        }
    }

    vector<vector<int>> ans(H, vector<int>(W, 0));
    int si = mp.size();
    bool newline = true;

    for (int k = 0; k <= H-h; k++) {
        newline = true;
        map<int,int> paint;

        for (int l = 0; l <= W-w; l++) {
            if (newline) {
                for (int i = k+1; i <= k+h; i++) {
                    for (int j = l+1; j <= l+w; j++) {
                       paint[a[i][j]]++; 
                    }
                }

                newline = false;
            } else { // 列を走査して差分計算
                for (int i = k+1; i <= k+h; i++) {
                    paint[a[i][l]] -= 1;
                    paint[a[i][l+w]] += 1;
                }
            }   

            int hoge = si;
            for (auto x : paint) {
                if (mp[x.first] == x.second) {
                    hoge--;
                }
            }
            ans[k][l] = hoge;
        }
    }

    for (int k = 0; k <= H-h; k++) {
        for (int l = 0; l <= W-w; l++) {
            cout << ans[k][l] << " ";
        }
        cout << endl;
    }

    return 0;
}
