#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> a, b;
int n, m;

bool check(int v) {
    int urite = 0;
    int kaite = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] <= v) urite++;
    }
    for (int i = 0; i < m; i++) {
        if (b[i] >= v) kaite++;
    }
    if (urite < kaite) return false;
    else return true;
}

int main()
{
    cin >> n >> m;
    a.resize(n); b.resize(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    int l = 0, r = 1000000001;
    while(r - l > 1) {
        int mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    cout << r << endl;
    return 0;
}
