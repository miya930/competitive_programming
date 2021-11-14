
/**
 * 30“_‰ð–@
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef vector<vector<int> > Graph;
int n;
Graph G(100010);
vector<int> dist(100010);

void getdist(int start) {

    for (int i = 0; i <= n; ++i) dist[i] = -1;
    queue<int> que;

    dist[start] = 0;
    que.push(start);

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
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        
        getdist(a);

        cout << dist[b] << endl;
    }
    return 0;
}
