#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int main()
{
    int n, p, q;
    cin >> n >> p >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<int> cnt(7);

    int ans = 0;
    for (int bits = 0; bits < (1<<7); ++bits) {
        bitset<7> bs(bits);
        if (bs.count() != 5) continue;
        int count = 1;
        int mod = 0;
        for (int i = 0; i < 7; ++i) {
            if (bits & (1<<i)) {
                count *= cnt[i];
                if (mod == 0) mod = (i+1)%p;
                else mod *= (i+1) % p;
            }
        }
        if (mod == q) ans += count;
    }
    cout << ans << endl;
}
