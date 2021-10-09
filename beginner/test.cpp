#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n;
    cin >> n;
    int a, b;
    vector<pair<int, int> > x;
    vector<int> ans(n+1, 0);

    rep(i, n) {
        cin >> a >> b;
        x.push_back({a, 1});
        x.push_back({a+b, -1});
    }

    sort(x.begin(), x.end());

    int cnt = 0;

    rep(i, x.size()-1) {
        cnt += x[i].second;
        ans[cnt] += (x[i+1].first - x[i].first);
    }

    rep(i, n-1) cout << ans[i+1] << " ";
    cout << ans[n] << endl;

    return 0;
}

