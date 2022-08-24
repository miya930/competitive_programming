#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int r, c;
    cin >> r >> c;

    int cr = 7, cc = 7;
    int ar = abs(cr - r);
    int ac = abs(cc - c);
    int ma = max(ar, ac);

    bool black = true;
    if (ma == 1 || ma == 3 || ma == 5 || ma == 7) black = false;

    if (black) cout << "black" << endl;
    else cout << "white" << endl;

    return 0;
}
