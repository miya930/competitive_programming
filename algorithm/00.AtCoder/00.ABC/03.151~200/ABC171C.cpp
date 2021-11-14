#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;

int main()
{
    ll n; cin >> n;
    string ans = "";

    while(n > 0) {
        n--;
        int m = n % 26;
        ans = char('a' + m) + ans;
        n /= 26;
    }
    cout << ans << endl;
}
