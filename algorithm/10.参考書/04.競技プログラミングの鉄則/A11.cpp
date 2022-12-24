#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> a;

bool check(int key, int val) {
    if (a[key] < val) return false;
    else return true;
}

int main()
{
    int n, x;
    cin >> n >> x;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    sort(a.begin(), a.end());

    int l = -1, r = n;
    while(r-l > 1) {
        int mid = (r+l)/2;
        if (check(mid, x)) r = mid;
        else l = mid;
    }

    cout << r << endl;

    return 0;
}
