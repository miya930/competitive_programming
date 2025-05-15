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
    int n, k;
    string s;
    cin >> n >> k >> s;
    int cnto = 0, cntq = 0;
    rep(i, 0, n) {
        if (s[i] == 'o') cnto++;
        else if (s[i] == '?') cntq++;
    }
    if (cnto == k) {
        rep(i, 0, n) {
            if (s[i] == '?') s[i] = '.';
        }
        cout << s << endl;
        return 0;
    } 
    rep(i, 0, n) {
        if (s[i] == 'o') {
            if (i>0 && s[i-1] == '?') s[i-1] = '.';
            if (i+1<n && s[i+1] == '?') s[i+1] = '.';
        }
    }
    string ns = s;
    rep(i, 0, n) {
        if(ns[i] != '?') continue;
        int cur = i;
        while(ns[cur] == '?') {
            cur++;
        }
        if ((cur-i)%2 == 1) {
            bool ok = true;
            rep(j, i, cur) {
                ns[j] = (ok ? 'o' : '.');
                ok = !ok;
            }
            cnto += (cur - i + 1) / 2; 
        } else {
            cnto += (cur - i) / 2;
        }
        i = cur;
    }
    cout << ((cnto > k) ? s : ns) << endl;
    return 0;
}
