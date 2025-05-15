#include <bits/stdc++.h>
using namespace std;
#define rep(i, fi, n) for (int i = fi; i < n; i++)
using ll = long long;
using pii = pair<int,int>;
constexpr int inf = 1001001001;
constexpr ll infl = 1LL << 62;
constexpr int dx[] = {1, 0, -1, 0};
constexpr int dy[] = {0, 1, 0, -1};
template<class T> bool chmax(T &a, T b) { return a < b && (a = b, true); };
template<class T> bool chmin(T &a, T b) { return a > b && (a = b, true); };

vector<string> rotateVector2(vector<string> &s, int h, int w, int angle) {
    vector<string> ret = s;
    rep(i, 0, h) rep(j, 0, w) {
        if (angle == 90) {
            ret[j][w-i-1] = s[i][j];
        } else if (angle == 180) {
            ret[h-i-1][w-j-1] = s[i][j];
        } else if (angle == 270) {
            ret[w-j-1][i] = s[i][j];
        }
    }
    return ret;
}

int h = 4, w = 4;


int main()
{
    vector<string> p1(h), p2(h), p3(h);
    rep(i, 0, h) cin >> p1[i];
    rep(i, 0, h) cin >> p2[i];
    rep(i, 0, h) cin >> p3[i];

    vector<int> ang(4);
    ang[0] = 0; ang[1] = 90; ang[2] = 180; ang[3] = 270;

    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    rep(i, 0, h) {
        rep(j, 0, w) {
            if (p1[i][j] == '#') cnt1++;
            if (p2[i][j] == '#') cnt2++;
            if (p3[i][j] == '#') cnt3++;
        }
    }

    for (int ang1 = 0; ang1 < 4; ang1++) {
        for (int ang2 = 0; ang2 < 4; ang2++) {
            for (int ang3 = 0; ang3 < 4; ang3++) {
                // 開店した図形
                vector<string> rp1 = rotateVector2(p1, h, w, ang[ang1]);
                vector<string> rp2 = rotateVector2(p2, h, w, ang[ang2]);
                vector<string> rp3 = rotateVector2(p3, h, w, ang[ang3]);

                // 左上橋
                int lx1, ly1, lx2, ly2, lx3, ly3;
                for (int i = 0; i < h; i++) {
                    for (int j = 0; j < w; j++) {
                        if (rp1[i][j] == '#') {
                            lx1 = i;
                            ly1 = j;
                            break;
                        }
                    }
                }
                for (int i = 0; i < h; i++) {
                    for (int j = 0; j < w; j++) {
                        if (rp2[i][j] == '#') {
                            lx2 = i;
                            ly2 = j;
                            break;
                        }
                    }
                }
                for (int i = 0; i < h; i++) {
                    for (int j = 0; j < w; j++) {
                        if (rp3[i][j] == '#') {
                            lx3 = i;
                            ly3 = j;
                            break;
                        }
                    }
                }
                vector<string> grid(h);
                rep(i, 0, h) grid[i] = "....";
                for (int of1x = -3; of1x <= 3; of1x++) {
                    for (int of1y = -3; of1y <= 3; of1y++) {
                        for (int of2x = -3; of2x <= 3; of2x++) {
                            for (int of2y = -3; of2y <= 3; of2y++) {
                                for (int of3x = -3; of3x <= 3; of3x++) {
                                    for (int of3y = -3; of3y <= 3; of3y++) {
                                        bool ng = false;
                                        vector<string> rr1 = grid, rr2 = grid, rr3 = grid;
                                        int cc1 = 0, cc2 = 0, cc3 = 0;
                                        for (int i = 0; i < h; i++) {
                                            for (int j = 0; j < w; j++) {
                                                int ii = i + of1x;
                                                int jj = j + of1y;
                                                if (ii < 0 || jj < 0 || ii >= h || jj >= w) continue;
                                                rr1[i][j] = rp1[ii][jj];
                                                if (rp1[ii][jj] == '#') cc1++;
                                            }
                                        }
                                        if (cc1 != cnt1) continue;
                                        for (int i = 0; i < h; i++) {
                                            for (int j = 0; j < w; j++) {
                                                int ii = i + of2x;
                                                int jj = j + of2y;
                                                if (ii < 0 || jj < 0 || ii >= h || jj >= w) continue;
                                                rr2[i][j] = rp2[ii][jj];
                                                if (rp2[ii][jj] == '#') cc2++;
                                            }
                                        }
                                        if (cc2 != cnt2) continue;
                                        for (int i = 0; i < h; i++) {
                                            for (int j = 0; j < w; j++) {
                                                int ii = i + of3x;
                                                int jj = j + of3y;
                                                if (ii < 0 || jj < 0 || ii >= h || jj >= w) continue;
                                                rr3[i][j] = rp3[ii][jj];
                                                if (rp3[ii][jj] == '#') cc3++;
                                            }
                                        }
                                        if (cc3 != cnt3) continue;

                                        vector<string> tgrid = rr1; 
                                        
                                        for (int i = 0; i < h; i++) {
                                            for (int j = 0; j < w; j++) {
                                                if (tgrid[i][j] == '#') {
                                                    if (rr2[i][j] == '#') ng = true;
                                                } else {
                                                    if (rr2[i][j] == '#') tgrid[i][j] = '#';
                                                }
                                            }
                                        }
                                        for (int i = 0; i < h; i++) {
                                            for (int j = 0; j < w; j++) {
                                                if (tgrid[i][j] == '#') {
                                                    if (rr3[i][j] == '#') ng = true;
                                                } else {
                                                    if (rr3[i][j] == '#') tgrid[i][j] = '#';
                                                }
                                            }
                                        }                                        
                                        for (int i = 0; i < h; i++) {
                                            for (int j = 0; j < w; j++) {
                                                if (tgrid[i][j] == '.') ng = true;
                                            }
                                        }
                                        if (!ng) {
                                            cout << "Yes" << endl;
                                            return 0;
                                        }
                                    }
                                }
                            }
                        }
                    }                    
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
