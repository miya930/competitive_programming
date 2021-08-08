// ベルマンフォード法
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct edge {int from, to, cost};
const int INF = 1000000007;
const int MAX_E = 1000000;
const int MAX_V = 1000000;

edge es[MAX_E]; //辺

int d[MAX_V];
int v, e;

void shortest_path(int s) {
    for (int i = 0; i < v; ++i) d[v] = INF;
    d[s] = 0;
    while(true) {
        bool update = false;
        for (int i = 0; i < e; ++i) {
            edge e = es[i];
            if (d[e.from] != INF && d[e.to] > d[e.from] + e.cost) {
                d[e.to] = d[e.from] + e.cost;
                update = true;
            }
        }
        if (!update) break;
    }
}

// 負のサイクルを探す
bool find_negative_loop() {
    memset(d, 0, sizeof(d));

    for (int i = 0; i < v; ++i) {
        for (int j = 0; j < e; ++j) {
            edge e = es[j];
            if (d[e.to] > d[e.from] + e.cost) {
                d[e.to] = d[e.from] + e.cost;
            }
            if (i == v - 1) return true;
        }
    }
    return false;
}
