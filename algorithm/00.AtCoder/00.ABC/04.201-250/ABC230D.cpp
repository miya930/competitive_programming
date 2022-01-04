#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, d; cin >> n >> d;
    vector<pair<int, int>> vec(n);
    for (int i = 0; i < n; ++i) cin >> vec[i].second >> vec[i].first;
    sort(vec.begin(), vec.end());

    int ans = 0;
    int now = 0;
    int right = vec[now].first;
    now++;
    while (now < n) {
        if (vec[now].second - right + 1 > d) {
            ans++;
            right = vec[now].first;
        }
        now++;
    }

    cout << ans+1 << endl;

    return 0;
}
