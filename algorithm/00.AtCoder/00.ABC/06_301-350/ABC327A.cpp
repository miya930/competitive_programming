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
    int n;
    string s;

    cin >> n >> s;
    rep(i, 0, n-1) {
        if ((s[i] == 'a' && s[i+1] == 'b') || (s[i] == 'b' && s[i+1] == 'a')) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;


    return 0;
}
