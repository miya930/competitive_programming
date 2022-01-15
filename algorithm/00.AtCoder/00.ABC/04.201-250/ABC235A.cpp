#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{  
    string s;
    cin >> s;

    int a = s[0] - '0', b = s[1] - '0', c = s[2] - '0';

    int tmp1 = 100*a + 10*b + c;
    int tmp2 = 100*b + 10*c + a;
    int tmp3 = 100*c + 10*a + b;

    cout << tmp1 + tmp2 + tmp3 << endl;

    return 0;
}
