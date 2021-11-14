#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> G[MAX_V];
int v;

int color[MAX_V];


bool dfs(int v, int c) {
    color[v] = c;

    for (int i = 0; i < G[v].size(); i++) {
        if (color[G[v][i]] == c) return false;
        if (color[G[v][i]] == 0 && !dfs(G[v][i], -c)) return false;
    }
    return true;
}

void solve() {
    for (int i = 0; i < v; ++i) {
        if (color[i] == 0) {
            if (!dfs(i, 1)) {
                printf("No\n");
                return;
            }
        }
    }
    pring("Yes\n");
}

