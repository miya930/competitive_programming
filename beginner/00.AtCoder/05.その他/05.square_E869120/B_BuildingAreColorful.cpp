#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
const long long INF = 1000000000000000000LL;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    long long ans = INF;

    for (int bits = 0; bits < (1<<(n-1)); ++bits) {
        int t = bitset<15>(bits).count();
        if (t != k-1) continue;

        long long pre = a[0];
        long long sum = 0;

        for (int i = 1; i < n; ++i) {
            if (bits & (1<<(i-1))) {
                if (pre + 1 < a[i]) pre = a[i];
                else {
                    sum += pre + 1 - a[i];
                    pre++;
                }
            } 
            else pre = max(pre, a[i]);
        }
        ans = min(ans, sum);
    }
    cout << ans << endl;
}
