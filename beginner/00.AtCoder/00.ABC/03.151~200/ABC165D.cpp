#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    ll a, b, n;
    cin >> a >> b >> n;

    ll ans = 0;
    if (n < b-1) {
        cout << a * n / b << endl;
    } else {
        cout << a * (b-1) / b << endl;
    }
    return 0;
}
