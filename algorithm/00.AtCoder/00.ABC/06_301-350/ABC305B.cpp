#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    char p, q;
    cin >> p >> q;

    string s = "ABCDEFG";
    vector<int> a(s.size()+1);
    a[1] = 3;
    a[2] = a[1] + 1;
    a[3] = a[2] + 4;
    a[4] = a[3] + 1;
    a[5] = a[4] + 5;
    a[6] = a[5] + 9;
    int u = p - 'A' ;
    int v = q - 'A' ;

    cout << a[max(u,v)] - a[min(u,v)] << endl;

    return 0;
}
