#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main()
{
    ll r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    ll bef_p = r1 + c1;
    ll bef_m = r1 - c1;
    ll af_p = r2 + c2;
    ll af_m = r2- c2;

    ll dis = abs(r1-r2) + abs(c1-c2);

    if (dis == 0) cout << 0 << endl;
    else if (dis <= 3) cout << 1 << endl;
    else if ((bef_p==af_p) || (bef_m==af_m)) cout << 1 << endl;
    else if (dis <= 6) cout << 2 << endl;
    else if ((bef_p-af_p)%2==0) cout << 2 << endl;
    else {
        if ((abs(bef_p - af_p) <= 3 ) || (abs(bef_m - af_m) <= 3)) cout << 2 << endl;
        else cout << 3 << endl;
    }
    return 0;
}
