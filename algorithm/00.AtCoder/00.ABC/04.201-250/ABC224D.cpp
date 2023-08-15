#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

int main()
{
    int m;
    cin >> m;
    Graph G(9);
    for (int i = 0; i < m; i++) {
        int u,v;
        cin >> u >>v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    string s = "999999999";
    for (int i = 0; i < 8; i++) {
        int p;
        cin >> p;
        s[p-1] = i + '0' + 1;
    }
    
    queue<pair<string, int>> que;
    map<string, int> mp;
    mp[s] = 0;
    que.push(make_pair(s, 0));
    
    while(!que.empty()) {
        string s1 = que.front().first;
        int d = que.front().second;
        que.pop();

        int v;
        for (int i = 0; i < 9; i++) {
            if (s1[i] == '9') v = i;
        }

        for (auto nv : G[v]) {
            string str = s1;
            swap(str[v], str[nv]);          
            if (mp.count(str)) continue;

            mp[str] = d + 1;
            que.push(make_pair(str, d+1));
        }
    }

    if (mp.find("123456789") == mp.end()) cout << -1 << endl;
    else cout << mp["123456789"] << endl;
    return 0;
}
