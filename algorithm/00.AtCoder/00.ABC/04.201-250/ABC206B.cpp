#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    long long sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += i;
        if (sum >= n) {
            cout << i << endl;
            return 0;
        }
    }
}
