#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> a(3*n);
    for (int i = 0; i < 3*n; i++) cin >> a[i];

    vector<int> cnt(n+1, 0);
    vector<pair<int,int>> pa(n);
    for (int i = 0; i < 3*n; i++) {
        cnt[a[i]]++;
        if (cnt[a[i]] == 2) {
            pa[a[i]-1].first = i;
            pa[a[i]-1].second = a[i];
        }
    }
    sort(pa.begin(), pa.end());

    for (int i = 0; i < n; i++) cout << pa[i].second << " ";
    cout << endl;

    return 0;
}
