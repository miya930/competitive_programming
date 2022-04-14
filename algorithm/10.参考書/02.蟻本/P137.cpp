#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
const int inf = 1001001001;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> st;
    map<int,int> mps;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        st.insert(a[i]);
    }

    int si = st.size();

    int r = 0;
    int cnt = 0;
    int ans = inf;
    for (int l = 0; l < n; ++l) {
        while(r < n && cnt < si) {
            if (mps[a[r]] == 0) cnt++;
            mps[a[r++]]++;
        }
        if (cnt < si) break;
        ans = min(ans, r-l);
        if (l == r) r++;
        mps[a[l]]--;
        if (mps[a[l]] == 0) {
            cnt--;
        }
    }

    cout << ans << endl;
    return 0;
}
