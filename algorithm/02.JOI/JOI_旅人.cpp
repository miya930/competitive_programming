#include <iostream>
#include <vector>
using namespace std;
const int MOD = 100000;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> s(n-1), a(n+1);
    for (int i = 0; i < n-1; i++) cin >> s[i];

    vector<int> sum(n);
    sum[0] = 0;
    for (int i = 0; i < n-1; ++i) sum[i+1] = sum[i] + s[i];

    long long ans = 0;
    long long pre = 0;
    for (int i = 0; i < m; ++i) {
        long long a; cin >> a;
        ans += abs (sum[a+pre] - sum[pre]);
        pre += a;
        ans %= MOD;
    }
    cout << ans << endl;    
}
