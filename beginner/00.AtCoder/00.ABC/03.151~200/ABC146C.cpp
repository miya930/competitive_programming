#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll MA = 1000000000LL;
ll a, b, x;

ll keta(ll n) {
    ll res = 0;
    while (n > 0) {
        res++;
        n /= 10;
    }
    return res;
}

bool que(ll n, ll m) {
    if ((x - a*n) >= b*keta(n)) return true;
    else return false;
}

int main()
{
    cin >> a >> b >> x;

    ll right = MA+1;
    ll left = 0;

    while (right - left > 1) {
        ll mid = (right+left)/2;
        ll mid_keta = keta(mid);
        if(que(mid, mid_keta)) left = mid;
        else right = mid;
    }
    cout << left << endl;

}
