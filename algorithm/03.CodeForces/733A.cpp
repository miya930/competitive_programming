#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int max_dig(int n) {
    int res = 0;
    while (n > 0) {
        res = max(res, n%10);
        n /= 10;
    }
    return res;
}

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t ;++i) {
        int n;
        cin >> n;
        
        cout << max_dig(n) << endl;
    }
    return 0;
}
