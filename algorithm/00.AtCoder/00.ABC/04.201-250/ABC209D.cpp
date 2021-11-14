#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef vector<vector<int> > Graph;

int main()
{
    int N, Q; cin >> N >> Q;
    Graph G(N);

    for (int i = 0; i < N-1; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        
        G[a].push_back(b);
        G[b].push_back(a);
    } 

    vector<int> dist(N, -1);
    queue<int> que;
    que.push(0);
    dist[0] = 0;

    while (!que.empty()){
        int v = que.front();
        que.pop();

        for (int nv : G[v]) {
            if (dist[nv] != -1) continue;
            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
    }

    for (int q = 0; q < Q; ++q) {
        int c, d;
        cin >> c >> d;
        c--; d--;

        if (dist[c]%2 == dist[d]%2) cout << "Town" << endl;
        else cout << "Road" << endl;
    }
}
