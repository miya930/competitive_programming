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

int n;
string r, c;
vector<vector<string>> row;

void dfs(int now, vector<string> &s) {
    if (now >= n) {
        // check
        bool ng = false;
        rep(i, 0, n) {
            int idx = -1;
            rep(j, 0, n) {
                if (s[j][i] == '.') continue;
                idx = j;
                break;
            }
            if (idx == -1) {
                ng = true;
                continue;
            }
            if (s[idx][i] != c[i]) ng = true;
        }
        rep(j, 0, n) {
            vector<int> vec(3, 0);
            rep(i, 0, n) {
                if (s[i][j] != '.') {
                    int num = s[i][j] - 'A';
                    vec[num]++;
                }
            }
            if (vec[0] == 1 && vec[1] == 1 && vec[2] == 1) {

            } else ng = true;
        }

        if (!ng ) {
            cout << "Yes" << endl;
            rep(i, 0, n) {
                rep(j, 0, n) {
                    cout << s[i][j];
                }
                cout << endl;
            }
            exit(0);

        } else return;
        
    }

    for (auto str : row[now]) {
        vector<string> ss = s;
        ss.push_back(str);
        dfs(now+1, ss);
    }
}

int main()
{

    cin >> n >> r >> c;
    string s = "ABC";
    rep(i, 3, n) s.push_back('.');
    sort(s.begin(), s.end());

    row.resize(n);
    do {
        rep(i, 0, n) {
            if (s[i] != '.') {
                rep(j, 0, n) {
                    if (s[i] == r[j]) {
                        row[j].push_back(s);
                    }
                }
                break;
            }
        }
        
    } while(next_permutation(s.begin(), s.end()));

    vector<string> ans;
    dfs(0, ans);
    cout << "No" << endl;

    return 0;
}
