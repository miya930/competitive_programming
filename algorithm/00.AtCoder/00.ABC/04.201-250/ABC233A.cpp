#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

int main()
{
    int x, y;
    cin >> x >> y;

    if (y > x)
       cout << ((y-x)+9)/10 << endl;
    else
        cout << 0 << endl;

    return 0;
}
