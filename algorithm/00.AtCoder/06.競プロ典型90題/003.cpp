#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef vector<vector<int> > Graph;
int n;
Graph G(100010);
vector<int> dist(100010, -1);

void getdist(int start) {

    for (int i = 1; i <= n; ++i) dist[i] = -1;

    queue<int> que;
    que.push(start);
    dist[start] = 0;

    while (!que.empty()) {
        int v = que.front();
        que.pop();

        for (int nv : G[v]) {
            if (dist[nv] != -1) continue;

            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
    }
}

int main()
{
    cin >> n;

    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    getdist(1);
    int maxn1 = -1, maxid = -1;
    for (int i = 1; i <= n; ++i) {
        if (maxn1 < dist[i]) {
            maxn1 = dist[i];
            maxid = i;
        }
    }

    getdist(maxid);
    int maxn2 = -1;
    for (int i = 1; i <= n; ++i) {
        maxn2 = max(maxn2, dist[i]);
    }

    cout << maxn2 + 1 << endl;
    return 0;
}


/*** 2022.3.13 復習 ***/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

vector<ll> dist;
queue<int> que;

void bfs(const Graph &G, int x) {
    que.push(x);
    dist[x] = 0;

    while(!que.empty()) {
        int v = que.front();
        que.pop();

        for (auto nv : G[v]) {
            if (dist[nv] != -1) continue;

            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    dist.assign(n, -1);
    Graph G(n);

    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    bfs(G, 0);
    int s = 0;
    ll d = 0;
    for (int i = 0; i < n; ++i) {
        if (d < dist[i]) {
            s = i;
            d = dist[i];
        }
    }

    dist.assign(n, -1);
    bfs(G, s);
    int g = 0;
    d = 0;
    for (int i = 0; i < n; ++i) {
        if (d < dist[i]) {
            g = i;
            d = dist[i];
        }
    }

    cout << d + 1 << endl;
    return 0;
}
