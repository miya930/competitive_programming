#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef vector<vector<int> > Graph;
vector<int> val(201010, 0);

vector<bool> seen;
vector<int> memo;

void dfs(const Graph& G, int v) {
    seen[v] = true;

    for (auto nv : G[v]) {
        if (seen[nv] == true) continue;
        val[nv] += val[v];
        dfs(G, nv);
    }
}

int main() {
    int n, Q;
    cin >> n >> Q;
    Graph G(n);

    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for (int q = 0; q < Q; ++q) {
        int p, x;
        cin >> p >> x;
        p--;
        val[p] += x;
    }

    seen.resize(n);
    dfs(G, 0);

    for (int i = 0; i < n; ++i) {
        cout << val[i] << " ";
    }
    cout << endl;
    return 0;

}
