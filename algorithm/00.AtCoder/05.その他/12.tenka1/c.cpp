#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int N;
    cin >> N;
    for (int h =1; h <= 3500; h++) {
        for (int n = 1; n <= 3500; n++) {
            int tmp = 4*h*n;
            if (tmp%N != 0) continue;
            tmp /= N;
            tmp -= (h+n);
            if (tmp <= 0) continue;
            if ((h*n)%tmp != 0) continue;
            else {
                cout << h << " " << n << " " << h*n/tmp << endl;
                return 0;
            }
        }
    }

    return 0;
}
