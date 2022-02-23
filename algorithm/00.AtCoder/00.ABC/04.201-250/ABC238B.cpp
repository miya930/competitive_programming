#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<int> vec;
    vec.push_back(0);
    for (int i = 0; i < n; ++i) {
        int siz = vec.size();
        for (int j = 0; j < siz; ++j) {
            vec[j] += a[i];
            vec[j] %= 360;
        }
        vec.push_back(0);
    }
    
    sort(vec.begin(), vec.end());
    int ans = 0;
    vec.push_back(360);
    for (int i = 0; i < vec.size()-1; ++i) {
        ans = max(ans, vec[i+1]-vec[i]);
    }

    cout << ans << endl;
    return 0;
}
