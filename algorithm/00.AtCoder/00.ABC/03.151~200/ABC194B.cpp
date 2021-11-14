/**
   created: 09.10.2021 12:45:12
**/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int> > a(n), b(n);
    for (int i = 0; i < n; ++i) {
        int s, t;
        cin >> s >> t;
        a[i] = make_pair(s, i);
        b[i] = make_pair(t, i);
    }    

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if (a[0].second != b[0].second) {
        cout << max(a[0].first, b[0].first) << endl;
        return 0;
    } else {
        int tempsum = a[0].first + b[0].first;
        int temp = min(max(a[0].first, b[1].first), max(a[1].first, b[0].first));
        
        cout << min(tempsum, temp) << endl;
    }


    return 0;
}
