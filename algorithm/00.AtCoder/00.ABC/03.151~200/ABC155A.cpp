#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    bool ng = false;
    if ((a == b) && (a != c)) ng = true;
    if ((a == c) && (a != b)) ng = true;
    if ((b == c) && (a != b)) ng = true;

    if (ng) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
