#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;

    if (l1 <= r2 && l2 <= r1) {
        cout << min(r1, r2) - max(l1, l2) << endl;
    } else cout << 0 << endl;

    return 0;
}
