#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;

    if (n <= 1000-1) cout << n << endl;
    else if (n <= 10000-1) cout << n-n%10 << endl;
    else if (n <= 100000-1) cout << n-n%100 << endl;
    else if (n <= 1000000-1) cout << n-n%1000 << endl;
    else if (n <= 10000000-1) cout << n-n%10000 << endl;
    else if (n <= 100000000-1) cout << n-n%100000 << endl;
    else if (n <= 1000000000-1) cout << n-n%1000000 << endl;

    return 0;
}
