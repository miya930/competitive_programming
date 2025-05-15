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
    map<string, int> mp;
    mp["tourist"] = 3858;
    mp["ksun48"] = 3679;
    mp["Benq"] = 3658;
mp["Um_nik"] = 3648;
mp["apiad"] = 3638;
mp["Stonefeang"] = 3630;
mp["ecnerwala"] = 3613;
mp["mnbvmar"] = 3555;
mp["newbiedmy"] = 3516;
mp["semiexp"] = 3481;

    string s; cin >> s;
    cout << mp[s] << endl;

    return 0;
}
