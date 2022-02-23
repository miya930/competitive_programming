#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);

    if (abs(a%10-b%10) == 1 || (a == 9 && b == 10)) cout << "Yes" << endl;
    else cout << "No"  << endl;

    return 0;
}
