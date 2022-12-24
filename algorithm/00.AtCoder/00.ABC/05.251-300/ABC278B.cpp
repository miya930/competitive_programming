#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int h, m;
    cin >> h >> m;
    
    while(1) {
        int hu = (h/10) %10;
        int hl = h%10;
        int mu = (m/10) % 10;
        int ml = m%10;
        
        int hh = hu*10 + mu;
        int mm = hl*10+ml;
        if (hh <= 23 && mm <=59) break;

        m++;
        if (m >= 60) {
            m = 0;
            h++;
            if (h >= 24) h = 0;
        }
    }

    cout << h << " " << m << endl;

    return 0;
}
