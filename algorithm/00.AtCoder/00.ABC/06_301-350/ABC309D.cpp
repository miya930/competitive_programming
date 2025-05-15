#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

int main()
{
    int n1, n2, m;
    cin >> n1 >> n2 >> m;
    Graph G(n1+n2);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<int> dist1(n1+n2, -1), dist2(n1+n2, -1);
    queue<int> que1, que2;
    dist1[0] = 0; dist2[n1+n2-1] = 0;
    que1.push(0);
    que2.push(n1+n2-1);
    while(!que1.empty()) {
        int v = que1.front();
        que1.pop();

        for (auto nv : G[v]) {
            if (dist1[nv] != -1) continue;
            dist1[nv] = dist1[v] + 1;
            que1.push(nv);
        }
    }
    while(!que2.empty()) {
        int v = que2.front();
        que2.pop();

        for (auto nv : G[v]) {
            if (dist2[nv] != -1) continue;
            dist2[nv] = dist2[v] + 1;
            que2.push(nv);
        }
    }

    int ma1 = 0, ma2 = 0;
    for (int i = 0; i < n1; i++) {
        ma1 = max(ma1, dist1[i]);
    }
    for (int i = n1; i < n1+n2; i++) {
        ma2 = max(ma2, dist2[i]);
    }

    cout << ma1 + ma2 + 1 << endl;

    return 0;
}
