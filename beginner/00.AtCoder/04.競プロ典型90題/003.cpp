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
