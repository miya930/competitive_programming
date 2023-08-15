#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    string ans = "";
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'o' && cnt < k) {
            cnt++;
            ans.push_back('o');
        } else {
            ans.push_back('x');
        }
    }

    cout << ans << endl;

    return 0;
}
