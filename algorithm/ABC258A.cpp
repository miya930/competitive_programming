#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int k;
    cin >> k;

    int t = k/60;
    int t2 = k%60;
    int t3 = t2%10;
    int t4 = t2/10;

    cout << "2" << (char)('1' + t) << ":" << (char)('0'+t4) << (char)('0' + t3) << endl;

    return 0;
}
