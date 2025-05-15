#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int a, b;
    cin >> a >> b;

    a -= 2*b;
    if (a <= 0) cout << 0 << endl;
    else cout << a << endl;

    return 0;
}
