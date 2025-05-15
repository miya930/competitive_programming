#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int a, b;
    cin >> a >> b;

    int diff = abs(a-b);
    int s = (a-1)/3;
    int t = (b-1)/3;

    if (diff == 1 && s == t) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
