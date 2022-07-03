#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int a, b;
    cin >> a >> b;

    cout << max(a+b, max(a-b, a*b)) << endl;

    return 0;
}
