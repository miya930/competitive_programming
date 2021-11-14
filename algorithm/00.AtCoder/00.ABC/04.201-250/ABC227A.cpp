#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, a;
    cin >> n >> k >> a;

    int now = a;
    while (k > 0) {
        now++;
        if (now > n) now = 1;
        k--;
    }


    if (now-1 == 0) cout << n << endl;
    else cout << now-1 << endl;

    return 0;
}
