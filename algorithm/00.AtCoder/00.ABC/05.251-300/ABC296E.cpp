#include <bits/stdc++.h>
#include <atcoder/scc>
using namespace std;
using namespace atcoder;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    scc_graph G(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        a--;
        G.add_edge(i, a);
        if (i == a) ans++;
    }
    auto scc = G.scc();

    for (auto c : scc) {
        if (c.size() >= 2) {
            ans += c.size();
        }
    }

    cout << ans << endl;
    return 0;
}
