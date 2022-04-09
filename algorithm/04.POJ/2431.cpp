#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    int n, l, p;
    cin >> n;
    vector<pair<int,ll>> pa(n);
    priority_queue<ll> que;
    for (int i = 0; i < n; ++i) cin >> pa[i].first >> pa[i].second;
    cin >> l >> p;
    for (int i = 0; i < n; ++i) pa[i].first = l - pa[i].first;

    sort(pa.begin(), pa.end());

    ll now = p;
    vector<ll> dist;
    dist.push_back(pa[0].first-0);
    for (int i = 0; i < n-1; ++i) {
        dist.push_back(pa[i+1].first - pa[i].first);
    }
    dist.push_back(l-pa[n-1].first);

    bool flag = true;
    int ans = 0;
    for (int i = 0; i < (int)dist.size(); ++i) {
        now -= dist[i];
        if (now < 0) {
            while(now < 0) {
                if (que.empty()) {
                    cout << -1 << endl;
                    return 0;
                }
                now += que.top();
                que.pop();
                ans++;
            }
        }
        que.push(pa[i].second);
    }

    cout << ans << endl;
    return 0;
}
