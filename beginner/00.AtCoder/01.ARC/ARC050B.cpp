#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main(void)
{
    ll R, B;
    int x, y;
    cin >> R >> B >> x >> y;

    ll left = 0, right = INF;
    while(right - left > 1) {
        ll k = (left+right)/2;
        if ((R-k)/(x-1)+(B-k)/(y-1)>= k && (R-k) >= 0 && (B-k) >= 0) left = k;
        else right = k;
    }
    cout << left << endl;
}
