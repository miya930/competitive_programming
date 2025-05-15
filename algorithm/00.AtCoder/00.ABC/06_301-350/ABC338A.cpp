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
    if (s[0] >= 'A' && s[0] <= 'Z') {
        int n = s.size();
        rep(i, 1, n) {
            if (s[i] >= 'a' && s[i] <= 'z') continue;
            cout << "No" << endl;
            return 0;
        }
    } else {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes"<< endl;

    return 0;
}
