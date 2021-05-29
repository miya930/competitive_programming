#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int> > x(n), y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i].first >> y[i].first;
        x[i].second = i;
        y[i].second = i;
    }

    sort(x.rbegin(), x.rend());
    sort(y.rbegin(), y.rend());

    vector<int> ans;
    ans.push_back(x[0].first-x[n-1].first);
    if ((x[0].second != y[0].second) || (x[n-1].second != y[n-1].second))ans.push_back(y[0].first-y[n-1].first);
    ans.push_back(x[0].first-x[n-2].first);
    ans.push_back(x[1].first-x[n-1].first);
    ans.push_back(y[0].first-y[n-2].first);
    ans.push_back(y[1].first-y[n-1].first);

    sort(ans.rbegin(), ans.rend());

    cout << ans[1] << endl;
}
