#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

queue<int> que;
vector<bool> seen;
vector<int> vec;

void bfs(const Graph &G, int x) {
    que.push(x);
    seen[x] = true;

    while(!que.empty()) {
        int v = que.front();
        que.pop();

        for (auto nx : G[v]) {
            if (seen[nx]) continue;

            seen[nx] = true;
            que.push(nx);
            vec.push_back(nx);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    seen.assign(n, false);
    Graph G(n+100);
    map<int,int> mp, mp2;
    vector<pair<int,int>> edge;
    set<int> st;
    st.insert(0);
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        st.insert(a);
        st.insert(b);
        edge.push_back(make_pair(a, b));
    }
    
    int idx = 0;
    for (auto x : st) {
        mp[x] = idx;
        mp2[idx] = x;
        idx++;
    }

    for (int i = 0; i < n; ++i) {
        int tx = edge[i].first;
        int ty = edge[i].second;
        int xx = mp[tx];
        int yy = mp[ty];
        G[xx].push_back(yy);
        G[yy].push_back(xx);
    }

    bfs(G, 0);

    int ans = 0;

    if (vec.size() == 0) {
        cout << 1 << endl;
    } else {
        for (int i = 0; i < vec.size(); ++i) {
            int tt = vec[i];
            int tmp = mp2[vec[i]];
            ans = max(ans, tmp);
        }
        cout << ans+1 << endl;
    }

    return 0;
}
