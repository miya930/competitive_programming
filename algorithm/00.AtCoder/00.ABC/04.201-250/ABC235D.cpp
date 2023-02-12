#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

int main()
{
    int a, n;
    cin >> a >> n;

    int m = 1;
    while(m <= n) {
        m *= 10;
    }

    vector<ll> dist(m+100, -1);
    dist[1] = 0;
    queue<int> que;
    que.push(1);

    while(!que.empty()) {
        int v = que.front();
        que.pop();
        ll nv = (ll)a * v;

        if (nv < m && dist[nv] == -1) {
            que.push(nv);
            dist[nv] = dist[v] + 1;
        }
        if (v >= 10 && v%10 != 0) {
            string s = to_string(v);
            string s1 = s.substr(s.size()-1, 1);
            string s2 = s.substr(0, s.size()-1);
            s1 = s1 + s2;
            
            ll nv2 = stoi(s1);

            if (v < m && dist[nv2] == -1) {
                que.push(nv2);
                dist[nv2] = dist[v] + 1;
            }
        }
    }

    cout << dist[n] << endl;

    return 0;
}
