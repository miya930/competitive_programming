#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;

    int a = n % 16;
    n /= 16;
    int b = n % 16;
    char aa, bb;
    if (a > 9) aa = (a%10+'A');
    else aa = (a + '0');

    if (b > 9) bb = (b%10+'A');
    else bb = (b + '0');

    cout << bb << aa << endl;

    return 0;
}
