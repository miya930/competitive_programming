#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, r;
    cin >> n >> r;

    if (n >= 10) cout << r << endl;
    else cout << r + 100*(10-n) << endl;

    return 0;
}
