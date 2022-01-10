#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<ll> vec1[100], vec2[100];

int main()
{
    long long n, k, p;
    cin >> n >> k >> p;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int mid = n / 2;
    for (int i = 0; i < (1 << mid); ++i) {
        ll cnt1 = 0, cnt2 = 0;
        for (int j = 0; j < mid; ++j) {
            if (i & (1 << j)) {
                cnt1 += a[j];
                cnt2 += 1;
            }
        }
        vec1[cnt2].push_back(cnt1);
    }
    for (int i = 0; i < (1 << (n - mid)); ++i) {
        ll cnt1 = 0, cnt2 = 0;
        for (int j = 0; j < n - mid; j++) {
            if (i & (1<<j)) {
                cnt1 += a[mid + j];
                cnt2 += 1;
            } 
        }
        vec2[cnt2].push_back(cnt1);
    }

    for (int i = 0; i <= n; ++i) {
        sort(vec1[i].begin(), vec1[i].end());
        sort(vec2[i].begin(), vec2[i].end());
    }

    ll answer = 0;
    for (int h = 0; h <= k; ++h) {
        for (int i = 0; i < (int)vec1[h].size(); ++i) {
            int pos1 = lower_bound(vec2[k-h].begin(), vec2[k-h].end(), p-vec1[h][i]+1) - vec2[k - h].begin();
            answer += (ll)pos1;
        }
    }
    
    cout << answer << endl;
}
