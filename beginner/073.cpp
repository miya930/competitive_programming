#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
const int mod =  1000000007;
typedef vector<vector<int> > Graph;

vector<bool> seen;
vector<bool> dp_a, dp_b;
vector<long long> cnt;

void dfs(const Graph &G, int v) {
    seen[v] = true;

    for (auto nv : G[v]) {
        if (seen[nv] == true) continue;
        dfs(G, nv);

        if (c[nv] == 'a') dp_a[nv] = true;
        if (c[nv] == 'b') dp_b[nv] = true;

        if (dp_a[nv] & dp_b[nv]) cnt *= 2;
        cnt %= mod;
    }
}

int main()
{
    int n;
    cin >> n;

    vector<string> c;
    Graph G(n);

    seen.assign(n, false);
    dp_a.assign(n+1, false);
    dp_b.assign(n+1, false);
    cnt.assign(n+1, 0);

    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }




}
