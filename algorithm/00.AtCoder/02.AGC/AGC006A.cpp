#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int n;
    string s, t;
    cin >> n >> s >> t;

    int ans = 2*n;
    for (int i = 0; i < n; ++i) {
        int cnt = 2*n;
        if (s[n-i-1]==t[0]) {
            for (int j = 0; j < n; ++j) {
                if (n-i-1+j>=n) break;
                if (s[n-i-1+j]!=t[j]) break;
                cnt--;
            }
        }
        ans = min(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}
