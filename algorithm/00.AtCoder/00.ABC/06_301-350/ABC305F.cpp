#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
vector<bool> vis;

vector<int> read_vector(void) {
    int k;
    cin >> k;
    vector<int> ret(k);
    for (int i = 0; i < k; i++) {
        cin >> ret[i];
        ret[i]--;
    }
    return ret;
}

void dfs(int v, int pre) {
    if (v == n-1) {
        string str;
        cin >> str;
        exit(0);
    }

    vis[v] = true;
    vector<int> vec = read_vector();

    for (auto nv : vec) {
        if (vis[nv]) continue;
        cout << nv + 1 << endl;
        dfs(nv, v);
    }

    cout << pre + 1 << endl;
    read_vector();
}

int main()
{
    cin >> n >> m;
    vis.assign(n, false);

    dfs(0, 0);

    return 0;
}
