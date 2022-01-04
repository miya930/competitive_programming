#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> a, c;

void MergeSort(int l, int r) {
    
    if (r - l == 1) return;

    int m = (l + r) / 2;
    MergeSort(l, m);
    MergeSort(m, r);

    int c1 = l, c2 = m, cnt = 0;
    while (c1 != m || c2 != r) {
        if (c1 == m) {
            c[cnt] = a[c2];
            c2++;
        } else if (c2 == r) {
            c[cnt] = a[c1];
            c1++;
        } else {
            if (a[c1] < a[c2]) {
                c[cnt] = a[c1];
                c1++;
            } else {
                c[cnt] = a[c2];
                c2++;
            }
        }
        cnt++;
    }

    for (int i = 0; i < cnt; ++i) a[l+i] = c[i];
}


int main()
{
    int n;
    cin >> n;
    a.resize(n);
    c.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    MergeSort(0, n);
    for (int i = 0; i < n; ++i) cout << a[i] << endl;

    return 0;
}
