#include <iostream>
using namespace std;

int main(void)
{
    int H, W;
    cin >> H >> W;

    if (H==1) {
        cout << W << endl;
        return 0;
    } else if (W == 1) {
        cout << H << endl;
        return 0;
    }

    int hh = (H+1)/2;
    int ww = (W+1)/2;

    cout << hh*ww << endl;
}

/*** 2022.3.13 復習 ***/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int h, w;
    cin >> h >> w;
    
    if (h == 1 || w == 1) cout << h*w << endl;
    else cout << ((h+1)/2)*((w+1)/2) << endl;

    return 0;
}
