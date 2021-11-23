#include <bits/stdc++.h>
using namespace std;

int main()
{
    int s, t, x;
    cin >> s >> t >> x;

    bool flag = false;
    if (s > t) t += 24;
    
    if (s <= x && x < t || (s-24) <= x && x < t-24) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
