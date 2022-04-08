#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int d, n;
    cin >> d >> n;

    int now = 1;
    for (int i = 0; i < d; ++i) now *= 100;

    
    if (n == 100) cout << now * n + now << endl;
    else cout << now * n << endl;

    return 0;
}
