#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int x, a, b;
    cin >> x >> a >> b;

    x -= a;
    x %= b;
    
    cout << x << endl;

    return 0;
}
