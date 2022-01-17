#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    cout << min(a, min(b, min(c, d))) << endl;

    return 0;
}
