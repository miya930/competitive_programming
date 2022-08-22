#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int y;
    cin >> y;

    int ans = 0;
    for (int i = 0; i < 3; ++i) {
        if ((y+ans)%4 == 2) break;
        else ans++;
    }

    cout << y + ans  << endl;
    return 0;
}
