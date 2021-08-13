#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> s(n);
    vector<int> a(n, 0);

    for (int i = 0 ; i < n; ++i) cin >> s[i];
    for (int i = 0 ; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (s[i][j] == '1') a[i] = max(a[i], j); 
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                ans++;
            }
        }
    }
    cout << ans << endl;

}
