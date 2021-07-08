#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> l(n);
    for (int i = 0; i < n; ++i) cin >> l[i];

    sort(l.begin(), l.end());

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            int temp = l[i] + l[j];
            int index = lower_bound(l.begin(), l.end(), temp) - l.begin();
            index--;
            ans += index - j;
        }
    } 

    cout << ans << endl;
}
