#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    cin >> n;
    string s = "";

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

   
    while (n != 0) {
        int digit = abs(n%(-2));
        s += (char)(digit + '0');
        n = (n - digit) / (-2); 
    }
    
    reverse(s.begin(), s.end());
    cout << s << endl;
    return 0;
}
