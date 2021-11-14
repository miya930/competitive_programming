#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1001001001;

void solve() {
    int n;
    cin >> n;
    vector<P> p(n);
    for (int i = 0; i < n; ++i) cin >> p[i].first >> p[i].second;
    sort(p.begin(), p.end());
    priority_queue<int, vector<int>, greater<int> > que;
    int x = 1;
    p.emplace_back(INF, INF);
    for (auto nv : p) {
        while (x < nv.first && que.size()) {
            if (que.top() < x) {
                cout << "No" << endl;
                return;
            }
            que.pop();
            x++;
        }
        x = nv.first;
        que.push(nv.second);
    }
    cout << "Yes" << endl;
    return;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) solve();
    return 0;
}