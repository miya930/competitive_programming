#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> l(n);
    for (int i = 0; i < n; ++i) cin >> l[i];
    vector<int> sum(n+1, 0);
    for (int i = 0; i < n; ++i) {
        sum[i+1] = sum[i] + l[i];
        if (sum[i+1] > x) {
            cout << i+1 << endl;
            return 0;
        }
    }
    
    cout << n+1 << endl;
    return 0;
}
