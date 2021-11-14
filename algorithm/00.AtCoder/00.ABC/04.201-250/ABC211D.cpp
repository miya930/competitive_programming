#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
typedef vector<vector<int> > Graph;
int n, m;
const int mod = 1000000007;
const long long inf = 1LL << 60;
long long cnt;

vector<int> dist;
vector<long long> cnt;
queue<int> que;

template<class T> bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

void bfs(const Graph &G, int x) {
    dist[x] = 0;
    que.push(x);

    while(!que.empty()) {
        int v = que.front();
        que.pop();

        for (auto nv : G[v]) {
            if (dist[nv] != -1) {
                if (dist[nv] == dist[v] + 1) {
                    cnt[nv] += cnt[v];
                    cnt[nv] %= mod;
                }
                continue;
            }
            
            dist[nv] = dist[v]+1;
            que.push(nv);
        }
    }
}

int main()
{
    cin >> n >> m;
    Graph G(n);
    seen.assign(n, false);

    dp.assign(n + 1, inf);
    dp_cnt.assign(n + 1, 0);
    dp_cnt[0] = 1;
    dp[0] = 0;

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    bfs(G, 0);

    if (dist[n - 1] != -1) {
        cout << cnt[n - 1] << endl;
    }
    else {
        cout << 0 << endl;
    }


}
