#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<bool> dp(110000, false);

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    for (int i = 1; i <= k; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i - a[j] >= 0) dp[i] = dp[i] || !dp[i - a[j]];
        }
    }

    if (dp[k]) cout << "First" << endl;
    else cout << "Second" << endl;
}

/*y•Ê‰ðz
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    vector<bool> dp(k+1, false);
    for (int i = 0; i <= k; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i-a[j]>=0 && dp[i-a[j]]==false) dp[i] = 1;
        }
    }
    
    if (dp[k]) cout << "First" << endl;
    else cout << "Second" << endl;

    return 0;
}
**/