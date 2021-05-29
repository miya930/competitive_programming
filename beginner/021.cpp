#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
typedef vector<vector<int> > Graph;
int n, m;
Graph G(m);

int main()
{
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }

    ll ans = 0;
    vector<int> dist(m, -1);
    queue<int> que;

    for (int i = 1; i <= m; ++i) {
        dist[i] = 0;
    }

}
