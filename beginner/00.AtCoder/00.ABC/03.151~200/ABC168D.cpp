#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef vector<vector<int> > Graph;
typedef vector<pair<int, int> > P;

queue<int> que;
vector<int> dist;
P vec;

void bfs(const Graph& G, int x) {
    dist[x] = 0;
    que.push(x);
    vec.push_back(make_pair(x, 0));

        while (!que.empty()) {
            int v = que.front();
            que.pop();

            for (auto nv : G[v]) {
                if (dist[nv] != -1) continue;
                dist[nv] = dist[v] + 1;
                vec.push_back(make_pair(nv, v));
                que.push(nv);
            }
        }
}

int main()
{
    int n, m;
    cin >> n >> m;
    Graph G(n);

    dist.assign(n, -1);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    bfs(G, 0);

    sort(vec.begin(), vec.end());
    cout << "Yes" << endl;
    for (int i = 1; i < vec.size(); ++i) {
        cout << vec[i].second + 1 << endl;
    }
    return 0;
}
