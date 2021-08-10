#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef vector<int> Graph;

vector<int> dist, ans;
vector<int> dp;
queue<int> que;

void bfs(const Graph &G, int x) {
    dist[x] = 0;
    que.push(v);
    ans[x] = 0;

    while(!que.empty()) {
        int v = que.front();
        que.pop();
        for (auto nv : G[v]) {
            if (dist[nv] != -1) continue;
            dist[nv] = dist[v] + 1;
            que.push(nv);
            ans[nv] = v;
        }
        
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    
    dp.assign(n, 0);
    dist.assign(n, -1);
    ans.resize(n);
    
    Graph G(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for (int i = 0; i < n; ++i) {
        if (dist[i] == -1) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    for (int i = 0; i < n; ++i) {
        cout << ans[i] + 1 << endl;
    }
    return 0;

}
