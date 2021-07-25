// P43 貪欲法 ～区間スケジューリング問題～

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int,int> > p(n);
    for (int i = 0; i < n; ++i) cin >> p[i].second >> p[i].first;

    sort(p.begin(), p.end());

    int ans = 1;
    int cur = p[0].first;
    for (int i = 1; i < n; ++i) {
        if (cur < p[i].second) {
            ans++;
            cur = p[i].first;
        }
    }
    cout << ans << endl;
}
