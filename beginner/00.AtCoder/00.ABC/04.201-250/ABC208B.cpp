#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int p;
    cin >> p;

    long long ans = 0;
    long long temp = 1;
    long long count = 2;
    while (p > 0) {
        if (p >= temp*count) {
            temp *= count;
            count++;
        } else {
            p -= temp;
            ans++;
            temp = 1;
            count = 2;
        }
    }

    cout << ans << endl;
}
