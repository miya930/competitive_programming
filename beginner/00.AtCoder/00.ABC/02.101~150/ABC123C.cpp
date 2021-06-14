#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll INF = 1000000000000000000LL;

int main()
{
    ll n;
    cin >> n;
    vector<ll> a(5);
    for (int i = 0 ; i < 5; ++i) cin >> a[i];

    ll mi = INF;
    for (int i = 0; i < 5; ++i) mi = min(mi, a[i]);

    cout << 5 + (n-1)/mi << endl;
}
