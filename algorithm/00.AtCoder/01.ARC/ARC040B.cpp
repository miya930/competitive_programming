#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, r;
    string s;
    cin >> n >> r >> s;

    int last = -1, ans = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '.') last = i;
    }
    if (last == -1) {
        cout << 0 << endl;
        return 0;
    }

    int pos = 0;
    while(1) {
        int ran = pos + r - 1;
        if (ran >= last) {
            ans++;
            break;
        } else if (s[pos] == 'o') {
            ans++;
            pos++;
        } else {
            for (int i = pos; i <= min(ran,n-1); ++i) {
                s[i] = 'o';
            }
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
