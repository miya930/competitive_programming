#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;

    if ((b == c-1) || (c == b-1) || (c == b && b != 0) || (c == 0 && b == 0 && d == 0) || (c == 0 && b == 0 && a == 0)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
