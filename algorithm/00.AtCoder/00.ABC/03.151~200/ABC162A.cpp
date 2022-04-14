#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;

    bool flag = false;
    for (int i = 0; i < 3; ++i) {
        if (n%10 == 7) flag = true;
        n /= 10;
    }

    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}
