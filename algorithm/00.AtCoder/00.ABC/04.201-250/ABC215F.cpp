#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int> > v(n);
    for (int i = 0; i < n; ++i) cin >> v[i].first >> v[i].second;

    sort(v.begin(), v.end());

    int left = 0;
    int right = 1000000001;
    while (right - left > 1) {
        int mid = (right + left) / 2;
        queue<pair<int, int> > que;
        bool exist = false;
        int mi = 1000000001, ma = 0;
        for (auto p : v) {
            while (!que.empty()) {
                if (que.front().first > p.first - mid) break;
                mi = min(mi, que.front().second);
                ma = max(ma, que.front().second);
                que.pop();
            }
            if (mi <= p.second - mid || ma >= p.second + mid) exist = true;
            que.push(p);
        }
        if (exist) left = mid;
        else right = mid;
    }
    cout << left << endl;
}
