#include <iostream>
#include <vector>
using namespace std;
const int INF = 1000000007;

int main()
{
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n ;++i) cin >> p[i];

    int ans = 0;
    int temp = INF;
    for (int i = 0; i < n; ++i) {
        if (temp >= p[i]) {
            ans++;
            temp = p[i];
        }       
    }
    cout << ans << endl;
}
