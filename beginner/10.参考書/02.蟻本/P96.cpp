// ダイクストラ法
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cost[MAX_V][MAX_E];
int d[MAX_V];
bool used[MAX_V];
int v;

void dijkstra(int s) {
    fill(d, d+v, INF);
    fill(used, used + v; false);
    d[s] = 0;

    while(true) {
        int v = -1;
        for (int u = 0; u < v; ++u) {
            if (!used[u] && (v == -1 || d[u] < d[v])) v = u;
        }
        if (v == -1) break;

        used[v] = true;

        for (int u = 0; u < v; ++u) {
            d[u] = min(d[u], d[v] + cost[v][u]);
        }
    }
}

