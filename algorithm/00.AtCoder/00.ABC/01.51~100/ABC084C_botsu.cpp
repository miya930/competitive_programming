#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> s(n), c(n), f(n);

    for (int i = n-1; i > 0; --i) cin >> c[i] >> s[i] >> f[i];
    c[0] = 0;
    s[0] = 0;
    f[0] = 0;
    
    vector<long long> ans(n, 0);

    for (int i = 1; i < n; ++i) {
        long long sum = c[i] + s[i];
        if (sum < s[i-1]) {
            sum += (s[i-1] - sum);
        } else if ((f[i-1] != 0) && (sum%f[i-1]) != 0) {
            while(sum%f[i-1]!=0) {
                sum++;
            }
        }
        ans[i] = sum + ans[i-1] - s[i-1];
    }

    reverse(ans.begin(), ans.end());

    for (int i = 0;i < n; ++i) cout << ans[i] << endl;
    return 0;

}
