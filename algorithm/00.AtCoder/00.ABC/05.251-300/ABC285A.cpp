#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int a, b;
    cin >> a >> b;

    if (a > b) swap(a, b);

    if ((2*a == b) || (2*a+1 == b)) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
