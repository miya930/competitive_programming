#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool les(pair<long double, int>lhs, pair<long double,int> rhs) {
    if (lhs.first != rhs.first) {
        return lhs.first < rhs.first;
    } else {
        return lhs.second < rhs.second;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

    vector<pair<long double, int>> pa;
    for (int i = 0; i < n; i++) {
        pa.push_back(make_pair((long double)(1.0 + (long double)b[i] * (long double)10000000000000.0/a[i]), i));
    }
    sort(pa.begin(), pa.end(), les);

    for (int i = 0; i < n; i++) {
        cout << pa[i].second + 1 << " ";
    }
    cout << endl;

    return 0;
}
