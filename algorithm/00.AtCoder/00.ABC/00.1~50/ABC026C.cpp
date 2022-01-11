#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1001001001;

int main()
{
    int n;
    cin >> n;
    vector<int> b(n, 0);
    for (int i = 1; i < n; ++i) {
        cin >> b[i];
        b[i]--;
    }

    vector<int> sal(n, 1);
    vector<pair<int,int>> mami(n, {0, inf});

    for (int i = n-1; i >= 1; --i) {
        mami[b[i]].first = max(mami[b[i]].first, sal[i]);
        mami[b[i]].second = min(mami[b[i]].second, sal[i]);
        sal[b[i]] = mami[b[i]].first + mami[b[i]].second + 1;
    }

    cout << sal[0] << endl;
    return 0;
}
