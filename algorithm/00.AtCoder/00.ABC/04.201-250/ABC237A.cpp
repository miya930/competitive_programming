#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    cin >> n;

    if ((n < (1LL<<31)) && n >= (-1LL*(1LL<<31))) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
