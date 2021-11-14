#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    int k = 0;
    for (int i = 0; i < 64; ++i) {
        if (n >= (1LL<<k)) k++;
        else break;
    }
    if (k > 0) k--;
    cout << k << endl;
}
