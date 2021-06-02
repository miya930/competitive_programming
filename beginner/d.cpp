#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
vector<long long> fee(1000000007);

int main() {
    int n, C;
    cin >> n >> C;
    vector<pair<int, int> > a(n), b(n);
    for (int i = 0; i < n; ++i) {
        int c;
        cin >> a[i].first >> b[i].first;
        cin >> c;
        a[i].second = c; b[i].second = c;
    }

    for (int i = 0; i < n; ++i) {
        fee[a[i].first] = a[i].second;
        fee[b[i].first+1] = -b[i].second;
    }
    
    int b_max = 0;
    for (int i = 0; i < n; ++i) {
        b_max = max(b_max, b[i].first);
    }

    for (int i = 0; i <= b_max; ++i) fee[i+1] += fee[i];
    
    ll ans = 0;
    for (int i = 0; i <= b_max; ++i) {
        if (fee[i] < C) ans += fee[i];
        else ans += C;
    }
    cout << ans << endl;

}
