#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int l = 0, r = n-1;
    int cnt = 0;
    bool flag = true;
    while(r-l>=0) {
        if ((a[r]+cnt)%2 == 0) {
            r--;
        } else {
            if ((a[l]+cnt)%2 == 1) {
                flag = false;
                break;
            } else {
                cnt++;
                l++;
            }
        }
    }

    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
