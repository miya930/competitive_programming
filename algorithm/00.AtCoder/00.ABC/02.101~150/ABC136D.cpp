#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string s;
    cin >> s;

    int n = s.size();
    int even = 0, odd = 0, l = 0, r = 0;
    vector<int> ans(n, 0);
    for (int i = 0; i < n; ++i) {
        if (i%2 == 0) even++;
        else odd++;

        if (i < n-1 && s[i] == 'R' && s[i+1] == 'L') {
            r = i; l = i + 1;
        } else if (i < n-1 && s[i] == 'L' && s[i+1] == 'R') {
            if (r%2 == 1) {
                ans[r] = odd;
                ans[l] = even;
            } else {
                ans[r] = even;
                ans[l] = odd;
            }
            even = 0;
            odd = 0;
        }
    }

    if (r%2 == 1) {
        ans[r] = odd;
        ans[l] = even;
    } else {
        ans[r] = even;
        ans[l] = odd;
    }


    for (int i = 0; i < n; ++i) cout << ans[i] << " ";
    cout << endl;
    return 0;
}
