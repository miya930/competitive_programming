#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1001001001;
vector<int> a, is;
int n, m;

bool check(int key) {
    is.assign(n, 0);

    int place = 0;
    for (int i = 0; i < m; ++i) {
        if (is[a[i]] == 0 && a[i] <= key) place++;
        is[a[i]]++; 
    }
    if (place <= key) return true;
    for (int i = m; i < n; ++i) {
        if (is[a[i-m]] == 1 && a[i-m] <= key) place--;
        is[a[i-m]]--;
        if (is[a[i]] == 0 && a[i] <= key) place++;
        is[a[i]]++;

        if (place <= key) return true;
    }

    return false;
}

int main()
{
    cin >> n >> m;
    a.resize(n);
    is.assign(2000000, 0);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int left = -1, right = inf;
    while (right - left > 1) {
        int mid = (right + left) / 2;
        if (check(mid)) right = mid;
        else left = mid;
    }

    cout << right << endl;
    return 0;
}
