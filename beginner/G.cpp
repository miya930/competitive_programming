#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;
int n, m;
const int MAXN = 17;
vector<vector<pair<ll, ll> > > dist(MAXN, vector<pair<ll, ll> >(MAXN));
vector<vector<pair<ll, ll> > > dp(1<<MAXN, vector<pair<ll, ll> >(MAXN));

pair<ll, ll> ret(int bit, int v, int s, ll count) {
    if (dp[bit][v].first != -1) return dp[bit][v].first;

    if (bit == 1<<n-1 && v == s) {
        dp[bit][v].second++;
        return dp[bit][v].first = 0;
    }

    ll res = INF;

    for (int u = 0; u < n; ++u) {
        if (bit & 1<<n || count + dist[v][u].first > dist[v][u].second) continue;

        if (res > ret(bit|1<<u, u, s, count + dist[v][u].first)) {
            res = ret(bit|1<<u, u, s, count + dist[v][u].first);
        }
    }

    dp[bit][v].second++;
    return dp[bit][v].first = res;
}

int main()
{
    cin >> n >> m;
    
    dist.assign(n, vector<pair<ll, ll> >(n, make_pair(INF, INF)));
    dp.assign(n, vector<ll>(n, make_pair(-1, 0)));

    for (int i = 0; i < m; ++i) {
        int s, t;
        ll d, time;
        s--; t--;
        dist[s][t] = make_pair(d, time);
    }

    pair<ll, ll> ans = ret(0, 0, 0, 0);

    cout << ans.first << " " << ans.second << endl;
    return 0;

}
