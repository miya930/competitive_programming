#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<vector<int> > Graph;

vector<bool> seen;
vector<int> vec(200100, 0);

void dfs(const Graph &G, int v) {
    seen[v] = true;

    for(auto nv : G[v]) {
        if (seen[nv]) continue;
        vec[nv] += vec[v];
        dfs(G, nv);
    }
}

int main()
{
    int n, q;
    cin >> n >> q;

    Graph G(n);

    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    for (int i = 0; i < q; ++i) {
        int p, x;
        cin >> p >> x;
        p--;
        vec[p] += x;
    }

}
