#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int ma = 1000000007;

bool is_prime(int n) {
    for (int i = 2; i*i<=n; ++i) {
        if (n%i == 0) return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;

    if (is_prime(n)) cout << "Yes" << endl;
    else cout << "No" << endl;
}
