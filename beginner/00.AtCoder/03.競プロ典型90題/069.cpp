#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int mod = 1000000007;

int binpower(int a, long long b) {
    int ans = 1;
    while(b != 0) {
        if (b % 2 == 1) {
            ans = (long long)(ans)*a % mod;
        }
        a = (long long)(a)*a % mod;
        b /= 2;
    }
    return ans;
}

int main()
{
    long long n;
    int k;
    cin >> n >> k;

    if (k == 1) {
        cout << (n == 1 ? 1 : 0) << endl;
    }
    else if (n == 1) {
        cout << k % mod << endl;
    }
    else if (n == 2) {
        cout << (long long)(k) * (k-1) % mod << endl;
    }
    else {
        cout << (long long)(k) * (k-1) % mod * binpower(k-2, n-2) % mod << endl;
    }
    return 0;
}
