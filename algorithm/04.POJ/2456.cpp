#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
const int inf = 1001001001;

int n, m;
vector<int> x;

bool check(int key) {
    int cnt = 1;
    int pre = x[0];
    for (int i = 1; i < n; ++i) {
        int t = x[i] - pre;
        if (t >= key) {
            pre = x[i];
            cnt++;
        }
    }
    if (cnt >= m) return true;
    else return false;
}

int main()
{
    
    cin >> n >> m;
    x.resize(n);
    for (int i = 0; i < n; ++i) cin >> x[i];
    sort(x.begin(), x.end());

    int l = 0, r = inf;
    while(r-l>1) {
        int mid = (r+l)/2;
        if (check(mid)) l = mid;
        else r = mid;
    }

    cout << l << endl;
    return 0;
}
