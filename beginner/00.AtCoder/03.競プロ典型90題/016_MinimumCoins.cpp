#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main(void)
{
    ll n, a, b, c;
    cin >> n >> a >> b >> c;

    ll ans = INF;
    for (int i = 0; i <= 9999; ++i) {
        for (int j = 0; j <= 9999; ++j) {
            if ((n-a*i-b*j)%c==0 && (n-a*i-b*j)>=0)
                ans = min(ans, i+j+(n-a*i-b*j)/c);
        }
    }
    cout << ans << endl;
}
