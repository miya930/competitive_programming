#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool bin_search(vector<int> s, int key) {
    int left = -1;
    int right = s.size();

    while (right - left > 1) {
        int mid = (right + left) / 2;
        if (s[mid] >= key) right = mid;
        else left = mid;
    }
    if (s[right] == key) return true;
    else return false;
}

int main()
{
    int n;
    cin >> n;
    vector<int> s(n);
    for (int i = 0; i < n; ++i) cin >> s[i];

    int q;
    cin >> q;
    vector<int> t(q);
    for (int i = 0; i < q; ++i) cin >> t[i];
    sort(s.begin(), s.end());

    int ans = 0;
    for (int i = 0; i < q; ++i) {
        if (bin_search(s, t[i])) ans++;
    }
    cout << ans << endl;
}
