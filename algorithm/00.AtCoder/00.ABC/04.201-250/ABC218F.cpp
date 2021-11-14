#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
using Graph = vector<vector<int> >;

queue<int> que;
vector<int> dist, shortest_path(410);

void bfs(const Graph &G, int s, int ngs, int ngt) {
    dist[s] = 0;
    que.push(s);

    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (auto nv : G[v]) {
            if (dist[nv] != -1) continue;
            if (v == ngs && nv == ngt) continue;
            dist[nv] = dist[v] + 1;
            shortest_path[nv] = v;
            que.push(nv);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    Graph G(n);
    vector<int> s(m), t(m);
    dist.assign(n, -1);
    for (int i = 0; i < m; ++i) {
        cin >> s[i] >> t[i];
        s[i]--; t[i]--;
        G[s[i]].push_back(t[i]);
    }

    bfs(G, 0, -1, -1);

    map<pair<int, int>, bool> mp;
    int last = n-1;
    for (int i = 0; i < n; ++i) {
        mp[make_pair(shortest_path[last], last)] = true;
        last = shortest_path[last];
        if (last==0) break;
    }

    int shortest = dist[n-1];

    for (int i = 0; i < m; ++i) {
        if (!mp[make_pair(s[i], t[i])]) {
            cout << shortest << endl;
            continue;
        }
        dist.assign(n, -1);
        bfs(G, 0, s[i], t[i]);

        cout << dist[n-1] << endl;
    }

    return 0;

}
