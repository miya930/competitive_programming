#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    int ans = 0;
    for (int i = 1; i <= b; ++i) {
        int temp = b/i - (a-1)/i;
        if (temp >= 2) ans = max(ans, i);
    }
    
    cout << ans << endl;
}
