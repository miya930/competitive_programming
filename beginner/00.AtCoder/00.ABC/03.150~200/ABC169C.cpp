#include <iostream>
using namespace std;
typedef unsigned long long ll;
typedef long double ld;

int main(void)
{
    ll A;
    ld B;
    cin >> A >> B;
    ll ib = (ll)(B*100+0.5);
    cout << A*ib/100 << endl;
    return 0;
}
