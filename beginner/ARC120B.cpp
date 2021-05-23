#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MOD = 998244353;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; ++i) cin >> s[i];

    ll ans = 1;
    for (int i = 0; i < w; ++i) {
        bool r_flag = false;
        bool b_flag = false;
        if (s[0][i] == 'R') {
            for (int j = 1; j < h; ++j) {
                if (i - j <= 0) break;
                if (s[j][i-j] == 'R') continue;
                else if (s[j][i-j] == 'B') {
                    cout << 0 << endl;
                    return 0;
                } else continue;
            }
        } else if (s[0][i] == 'B') {
            for (int j = 1; j < h; ++j) {
                if (i-j <= 0) break;
                if (s[j][i-j] == 'B') continue;
                else if (s[j][i-j] == 'R') {
                    cout << 0 << endl;
                    return 0;
                } else continue;
            }
        } else if (s[0][i] == '.') {
            for (int j = 1; j < h; ++j) {
                if (i-j <= 0) {
                    if (r_flag || b_flag) {
                        break;
                    }
                    if (s[j][i-j] == 'R' || s[i][j-i] == 'B') break;
                    ans *= 2;
                    ans %= MOD;
                    break;
                } 
                if (s[j][i-j] == '.') {
                    continue;
                } else if (s[j][i-j] == 'R') {
                    r_flag = true;
                    if (r_flag && b_flag) {
                        cout << 0 << endl;
                        return 0;
                    }
                } else if (s[j][i-j] == 'B') {
                    b_flag = true;
                    if (r_flag && b_flag) {
                        cout << 0 << endl;
                        return 0;
                    }
                }
            }
        } 
    }

    for (int i = 1; i < h; ++i) {
        bool r_flag = false;
        bool b_flag = false;
        if (i == h-1) {
            if (s[i][w-1] == '.') {
                ans *= 2;
                ans %= MOD;
                break;
            } else break;
        }
        if (s[i][w-1] == 'R') {
            for (int j = 1; j < h; ++j) {
                if (i+j >= h) break;
                if (s[i+j][w-1-j] == 'R') continue;
                else if (s[i+j][w-1-j] == 'B') {
                    cout << 0 << endl;
                    return 0;
                } else continue;
            }
        } else if (s[i][w-i] == 'B') {
            for (int j = 1; j < h; ++j) {
                if (i+j >= h) break;
                if (s[i+j][w-1-j] == 'B') continue;
                else if (s[i+j][w-1-j] == 'R') {
                    cout << 0 << endl;
                    return 0;
                } else continue;
            }
        } else if (s[i][w-i] == '.') {
            for (int j = 1; j < h; ++j) {
                if (i+j >= h) {
                    if (r_flag || b_flag) {
                        break;
                    }
                    if (s[i+j][w-1-j] == 'R' || s[i+j][w-1-j] == 'B') break;
                    ans *= 2;
                    ans %= MOD;
                    break;
                }
                if (s[i+j][w-1-j] == 'R') {
                    r_flag = true;
                    if (r_flag && b_flag) {
                        cout << 0 << endl;
                        return 0;
                    }
                } else if (s[i+j][w-1-j] == 'B') {
                    b_flag = true;
                    if (r_flag && b_flag) {
                        cout << 0 << endl;
                        return 0;
                    }
                } else continue;
            }
        }
    }
    cout << ans << endl;
}
