#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;

int main()
{
    ll h, w, n;
    cin >> h >> w >> n;

    vector<ll> a(n), b(n);
    for (ll i = 0 ; i < n; ++i) {
        cin >> a[i] >> b[i];
    }

    vector<pair<ll, ll> > vec_x, vec_y;

    for (int i = 0 ; i < n; ++i) {
        vec_x.push_back(make_pair(a[i], i));
        vec_y.push_back(make_pair(b[i], i));
    }

    sort(vec_x.begin(), vec_x.end());
    sort(vec_y.begin(), vec_y.end());
    map<ll, ll> mp_x, mp_y;
    ll cnt_x = 1, cnt_y = 1;

    for (int i = 0; i < n; ++i) {
        if (mp_x[vec_x[i].first] == 0) {
            mp_x[vec_x[i].first]++;
            a[vec_x[i].second] = cnt_x;
            cnt_x++;
        } else {
            cnt_x--;
            a[vec_x[i].second] = cnt_x;
            cnt_x++;
        }
        if (mp_y[vec_y[i].first] == 0) {
            mp_y[vec_y[i].first]++;
            b[vec_y[i].second] = cnt_y;
            cnt_y++;
        } else {
            cnt_y--;
            b[vec_y[i].second] = cnt_y;
            cnt_y++;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << a[i] << " " << b[i] << endl;
    }
    return 0;
    
}
