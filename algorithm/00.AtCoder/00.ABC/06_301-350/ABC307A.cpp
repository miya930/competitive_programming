#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> a(7*n);
    for(int i = 0;i < 7*n; i++) cin >> a[i];

    for (int i = 0; i < 7*n; i += 7) {
        int sum = 0;
        for (int j = 0; j < 7; j++) {
            sum += a[i+j];
        }
        cout << sum << " ";
    }
    cout << endl;

    return 0;
}
