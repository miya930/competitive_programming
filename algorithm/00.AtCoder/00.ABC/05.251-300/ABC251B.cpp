#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, w;
    cin >> n >> w;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    map<int,int> mp;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            for (int k = j+1; k < n; ++k) {
                int sum = a[i] + a[j] + a[k];
                if (a[i] + a[j] + a[k] <= w) mp[sum]++;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            int sum = a[i] + a[j];
            if (a[i] + a[j] <= w) mp[sum]++;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] <= w) mp[a[i]]++;
    }

    cout << mp.size() << endl;
    return 0;
}
