/**
   created: 17.10.2021 23:15:54
**/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> indeg(n);
    vector<vector<int> > out(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        out[a].push_back(b);
        indeg[b]++;
    } 

    priority_queue<int, vector<int>, greater<int> > heap;
    for (int i = 0; i < n; ++i) {
        if (indeg[i] == 0) {
            heap.push(i);
        }
    }
    vector<int> ans;
    while(!heap.empty()) {
        int i = heap.top();
        heap.pop();
        ans.push_back(i);
        for (auto v : out[i]) {
            indeg[v]--;
            if (indeg[v] == 0) {
                heap.push(v);
            }
        }
    }

    if (ans.size() != n) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < (int)ans.size(); ++i) cout << ans[i]+1 << " ";
        cout << endl;
    }

    return 0;
}
