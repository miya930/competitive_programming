#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    long long ans = 0;
    for (int i = 1; i < n; ++i) {
        ans += (n-1)/i;
    }
    cout << ans << endl;
}
