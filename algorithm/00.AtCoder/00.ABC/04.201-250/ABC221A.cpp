#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    long long ans = 1;
    for (int i = 0; i < a-b; ++i) {
        ans *= 32;
    }
    cout << ans << endl;
}
