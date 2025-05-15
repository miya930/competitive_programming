#include <bits/stdc++.h>
using namespace std;
#define rep(i, fi, n) for (int i = fi; i < n; i++)
using ll = long long;
using pii = pair<int, int>;
constexpr int inf = 1001001001;
constexpr ll infl = 1LL << 62;
constexpr int dx[] = {1, 0, -1, 0};
constexpr int dy[] = {0, 1, 0, -1};
template <class T>
bool chmax(T &a, T b) { return a < b && (a = b, true); };
template <class T>
bool chmin(T &a, T b) { return a > b && (a = b, true); };

int main()
{
    int a1, a2, a3, a4;
    cin >> a1 >> a2 >> a3 >> a4;
    vector<int> vec(5);
    vec[a1]++;
    vec[a2]++;
    vec[a3]++;
    vec[a4]++;

    int ans = 0;
    for (int i = 1; i < 5; i++)
    {
        if (vec[i] >= 2)
            ans++;
        if (vec[i] >= 4)
            ans++;
    }
    cout << ans << endl;
    return 0;
}
