#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;

        if (a+b == c) {
            cout << i + 1 << endl;
            return 0;
        }
    }

    return 0;
}
