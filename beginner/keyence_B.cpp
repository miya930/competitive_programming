#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> x(n), l(n);
    for (int i = 0; i < n; ++i) cin >> x[i] >> l[i];

    vector<pair<int, int> > vec(n);
    for (int i = 0; i < n; ++i) {
        vec[i].first = x[i] + l[i];
        vec[i].second = x[i] - l[i];
    }
    
    sort(vec.begin(), vec.end());

    int ans = 1;
    int now = vec[0].first;
    for (int i = 1; i < n; ++i) {
        if (now <= vec[i].second) {
            ans++;
            now = vec[i].first;
        }
    }
    cout << ans << endl;
}
