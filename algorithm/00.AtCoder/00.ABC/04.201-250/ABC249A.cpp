#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int a, b, c, d, e, f, x;
    cin >> a >> b >> c >> d >> e >> f >> x;
    
    int s = (x / (a+c)) * a*b;
    int t = (x / (d+f)) * d*e;

    s += (min(x%(a+c), a)*b);
    t += (min(x%(d+f), d)*e);

    if (s > t) cout << "Takahashi" << endl;
    else if (s == t) cout << "Draw" << endl;
    else cout << "Aoki" << endl;

    return 0;
}
