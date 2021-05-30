#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
const ll INF = 1000000000000000000LL;

int main()
{
    int n;
    cin >> n;
    vector<pair<ll, char> > a(2*n);
    for (int i = 0; i <2*n; ++i) cin >> a[i].first >> a[i].second;

    map<char, int> cnt;

    for (int i = 0; i < 2*n; ++i) cnt[a[i].second]++;

    bool r_flag = false;
    bool b_flag = false;
    bool g_flag = false;

    if (cnt['R']%2 == 0) r_flag = true;
    if (cnt['B']%2 == 0) b_flag = true;
    if (cnt['G']%2 == 0) g_flag = true;

    if (r_flag & b_flag & g_flag) {
        cout << 0 << endl;
        return 0;
    }

    vector<ll> resu_1, resu_2, resu3;

    if (r_flag) {
        for (int i = 0; i < 2*n; ++i) {
            if (a[i].second == 'B') resu_1.push_back(a[i].first);
            else if(a[i].second == 'G') resu_2.push_back(a[i].first);
            else 
        }
    } else if (b_flag) {
        for (int i = 0; i < 2*n; ++i) {
            if (a[i].second == 'R') resu_1.push_back(a[i].first);
            else if (a[i].second == 'G') resu_2.push_back(a[i].first);
        }
    } else if (g_flag) {
        for (int i = 0; i < 2*n; ++i) {
            if (a[i].second == 'R') resu_1.push_back(a[i].first);
            else if (a[i].second == 'B') resu_2.push_back(a[i].first);
        }
    }

    sort(resu_1.begin(), resu_1.end());
    sort(resu_2.begin(), resu_2.end());

    ll ans = INF;
    for (int i = 0; i < (int)resu_2.size(); ++i) {
        int index_u = upper_bound(resu_1.begin(), resu_1.end(), resu_2[i]) - resu_1.begin();
        if (ans > abs(resu_1[index_u-1] - resu_2[i]))
            ans = abs(resu_1[index_u-1] - resu_2[i]);
        if (index_u < (int)resu_1.size()) {
            if (ans > abs(resu_1[index_u] - resu_2[i]))
                ans = abs(resu_1[index_u] - resu_2[i]);
        }
    }
    cout << ans << endl;
}
