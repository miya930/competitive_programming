#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n), list(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    for (int i = 0; i < n; ++i) list[i] = a[0]^b[i];

    vector<int> ans;
    sort(b.begin(), b.end());
    sort(list.begin(), list.end());
    for (int i = 0; i < n; ++i) {
        vector<int> vec(n);

        for (int j = 0; j < n; ++j) {
            vec[j] = list[i] ^ a[j];
        }
        sort(vec.begin(), vec.end());

        bool flg = true;
        for (int k = 0; k < n; ++k) {
            if (vec[k] != b[k]) flg = false;
        }

        if (flg) ans.push_back(list[i]);
    }
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    cout << ans.size() << endl;
    for (int i = 0; i < (int)ans.size(); ++i) {
        cout << ans[i] << endl;
    }
}
