#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main()
{
    ll a, b, c;
    cin >> a >> b >> c;

    if (c%2==1) c = 1;
    else c = 2;

    if (c == 2){
        a = a*a;
        b = b*b;
    }
    
    if (a < b) cout << '<' << endl;
    else if (a > b) cout << '>' << endl;
    else cout << '=' << endl;
}
