#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    long long res = 0;
    for (int i = 0; i < n; ++i) {
        res += i;
    }
    cout << res << endl;
}
