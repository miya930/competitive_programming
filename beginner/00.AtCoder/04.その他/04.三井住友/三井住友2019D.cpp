#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;

    string t = "000";

    for (char i = '0'; i <= '9'; ++i) {
        t[0] = i;
        for (char j = '0'; j <= '9'; ++j) {
            t[1] = j;
            for (char k = '0'; k <= '9'; ++k) {
                t[2] = k;
                vector<int> b(3, 0);
                int l = 0;
                for (int m = 0; m < 3; m++) {
                    while (l < n) {
                        if (t[m] == s[l]) {
                            b[m] = l;
                            l++;
                            break;
                        }
                        l++;
                    }
                }
                if (b[0] < b[1] && b[1] < b[2]) ans++;
            }
        }
    }
    cout << ans << endl;
}


/***
 * 
 * 2021.8.21 別解
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<vector<int> > next(string s) {
    int n = s.size();
    vector<vector<int> > vec(n+1, vector<int>(10, n));
    for (int i = n-1; i >= 0; --i) {
        for (int j = 0; j < 10; ++j) vec[i][j] = vec[i+1][j];
        vec[i][s[i]-'0'] = i;
    }
    return vec;
}

int main()
{
    int n;
    string s;
    cin >> n >> s;
    
    vector<vector<int> > nxt = next(s);
    int ans = 0;
    for (int i = 0; i <= 9; ++i) {
        for (int j = 0; j <= 9; ++j) {
            for (int k = 0; k <= 9; ++k) {
                int ii = nxt[0][i];
                if (ii == n) continue;
                int jj = nxt[ii+1][j];
                if (jj == n) continue;
                int kk = nxt[jj+1][k];
                if (kk == n) continue; 
                ans++;
            }
        }
    }
    cout << ans << endl; 
}
