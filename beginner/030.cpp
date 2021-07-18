#include <iostream>
#include <vector>
using namespace std;
const int num = 10000100;

int main()
{
    int n, k;
    cin >> n >> k;
    
    vector<int> c(n+1);
    for (int i = 2; i < n; ++i) {
        if(c[i] != 0) continue;
        for (int j = i; j <=n; j += i) c[j]++;
    }

    long long ans = 0;
    for (int i = 0; i <= n; ++i) {
        if (c[i] >= k) ans++;
    }
    cout << ans << endl;
}
