#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int t = a*60+b;
    int s = c*60+d;
    
    if (t <= s) cout << "Takahashi" << endl;
    else cout << "Aoki" << endl;

    return 0;
}
