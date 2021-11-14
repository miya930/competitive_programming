#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int prev[MAX_V];

void dijkstra(int s) {
    fill(d, d+v, INF);
    fill(used, used+v, false);
    fill(prev, prev+v, -1);
    d[s] = 0;

    while(true){
        int v = -1;

        for (int u = 0; u < v; u++) {
            if (!used[u] && (v == -1 || d[u] < d[v])) v = u;
        }

        if (v == -1) break;
        used[v] = true;

        for (int u = 0; u < v; ++u) {
            if (d[u] > d[v] + cost[v][u]) {
                d[u] = d[v] + cost[v][u];
                prev[u] = v;
            }
        }
    }
}

vector<int> get_path(int t) {
    vector<int> path;

    for (; t != -1; t = prev[t]) path.push_back(t); // t‚ªs‚É‚È‚é‚Ü‚Åprev[t]‚ð‚½‚Ç‚Á‚Ä‚¢‚­
    reverse(path.begin(), path.end());
    return path;
}

