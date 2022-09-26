#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;

    int a = 1, b = n+1, c = 1, d = n;
    int aa = a, bb = b;
    while(b-a>1) {
        int t;
        int mid1 = (a+b)/2;

        cout << "?" << " " << a << " " << mid1-1 << " " << c << " " << d << endl;
        cin >> t;

        if (t == (mid1-a)) a = mid1;
        else b = mid1;
    }

    bb = n; d = n+1;
    while(d-c>1) {
        int t;
        int mid1 = (c+d)/2;

        cout << "?" << " " << aa << " " << bb << " " << c << " " <<  mid1-1 << endl;
        cin >> t;

        if (t == (mid1-c)) c = mid1;
        else d = mid1;        
    }

    cout << "! " << a << " " << c << endl; 

    return 0;
}
