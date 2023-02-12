#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll infl = 1LL << 60;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    
    vector<vector<ll>> dist(n, vector<ll>(n, infl)), value(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                dist[i][j] = 0;
                value[i][j] = 0;
            } else if (s[i][j] == 'Y') {
                dist[i][j] = 1;
                value[i][j] = a[j];
            }
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][j] > dist[i][k]+dist[k][j]) {
                    dist[i][j] = dist[i][k]+dist[k][j];
                    value[i][j] = value[i][k]+value[k][j];
                } else if (dist[i][j] == dist[i][k]+dist[k][j]) {
                    if (value[i][j] < value[i][k]+value[k][j]) {
                        value[i][j] = value[i][k]+value[k][j];
                    }
                }
            }
        }
    }

    int Q;
    cin >> Q;
    for (int q = 0; q < Q; q++) {
        int u,v;
        cin >> u >> v;
        u--; v--;
        if (dist[u][v] < infl) cout << dist[u][v] << " " << value[u][v] + a[u] << endl;
        else cout << "Impossible" << endl;
    }

    return 0;
}
