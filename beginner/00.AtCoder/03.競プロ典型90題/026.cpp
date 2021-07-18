#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef vector<vector<int> > Graph;

vector<int> dist, ans_even, ans_odd;
queue<int> que;

void bfs(const Graph& G, int x) {
    dist[x] = 0;
    que.push(x);
    ans_even.push_back(x + 1);

    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (int nv : G[v]) {
            if (dist[nv] != -1) continue;
            dist[nv] = dist[v] + 1;
            que.push(nv);
            if (dist[nv] % 2 == 0) ans_even.push_back(nv + 1);
            if (dist[nv] % 2 == 1) ans_odd.push_back(nv + 1);
        }
    }
}

int main()
{
    int n;
    cin >> n;

    Graph G(n);
    dist.assign(n, -1);

    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    bfs(G, 0);

    if ((int)ans_even.size() < (int)ans_odd.size()) {
        for (int i = 0; i < n/2; ++i) cout << ans_odd[i] << " ";
    }
    else {
        for (int i = 0; i < n/2; ++i) cout << ans_even[i] << " ";
    }
    cout << endl;
}
