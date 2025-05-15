#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;

    int x = n%5;
    if (x < 3) cout << n - x << endl;
    else cout << n + (5-x) << endl;

    return 0;
}
