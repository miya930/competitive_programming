#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    cin >> n;
    string ans = "";

    while (n > 0) {
        if (n%2 == 1) {
            n--;
            ans = ans + "A";
        } else {
            n /= 2;
            ans = ans + "B";
        }
    }
    reverse(ans.begin(), ans.end());
    
    cout << ans << endl;

}
