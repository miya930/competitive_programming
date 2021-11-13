#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;

int main()
{
    double n;
    cin >> n;

    int c = n*10;
    if (c%10 >= 5) {
        c /= 10;
        c++;
    } else {
        c /= 10;
    }

    cout << c << endl;

    return 0;
}
