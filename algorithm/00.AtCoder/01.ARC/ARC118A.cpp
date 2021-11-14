#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main()
{
    ll t, n;
    cin >> t >> n;

    if ((100*n)%t == 0)
        cout << (ll)(100.0*n/t + n) - 1 << endl; 
    else
        cout << (ll)(100.0*n/t + n) << endl;
}
