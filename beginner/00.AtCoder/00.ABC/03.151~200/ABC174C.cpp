#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int k;
    cin >> k;

    vector<int> a(k+1, 0);

    for (int i = 0; i < k; ++i) {
        a[i+1] = (a[i]*10+7) % k;
        if ( a[i+1] == 0) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
