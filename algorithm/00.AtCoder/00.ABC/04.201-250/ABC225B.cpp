#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;
using Graph = vector<vector<int> >;

int main()
{
    int n;
    cin >> n;
    
    Graph G(n);

    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a  >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    bool ans = false;
    for (int i = 0; i < n; ++i) {
        int m = G[i].size();
        
        if (m == n-1) ans = true;
    }

    if (ans) cout << "Yes" << endl;
    else  cout << "No" << endl;

    return 0;
}
