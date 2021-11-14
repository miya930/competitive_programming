#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int ma = 1000000;
vector<bool> prime(ma, true);

int main()
{
    int n;
    cin >> n;

    prime[0] = false; prime[1] = false;

    for (int i = 2; i < ma; ++i) {
        for (int j = 2*i; j < ma; j += i) {
            prime[j] = false;
        } 
    }

    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        if (prime[i] == true) ans++; 
    }
    cout << ans << endl;
}
