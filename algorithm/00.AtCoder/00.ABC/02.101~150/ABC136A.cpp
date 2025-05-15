#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    int diff = a-b;
    cout << max(0, c-diff) << endl;

    return 0;
}
