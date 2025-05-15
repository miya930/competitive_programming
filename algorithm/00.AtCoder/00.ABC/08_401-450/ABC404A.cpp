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


int main()
{
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    for (int i = 0; i < 26; i++) {
        char c = 'a' + i;
        bool exist = false;
        for (int j = 0; j < s.size(); j++) {
            if (c == s[j]) {
                exist = true;
            }
        }
        if (!exist) {
            cout << c << endl;
            return 0;
        }
    }
    return 0;
}
