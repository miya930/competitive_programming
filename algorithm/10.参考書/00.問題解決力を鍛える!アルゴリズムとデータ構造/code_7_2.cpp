#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

using Internal = pair<int, int>;

bool cmp(const Internal &a, const Internal &b) {
    return a.second < b.second;
}

int main(void)
{
    int N;
    cin >> N;
    vector<Internal> inter(N);
    for (int i = 0; i < N; ++i) cin >> inter[i].first >> inter[i].second;

    sort(inter.begin(), inter.end(), cmp);

    // æÃ—~‚É‘I‚Ô
    int ans = 0;
    int current_end_time = 0;
    for (int i = 0; i < N; ++i) {
        if(inter[i].second) < current_end_time) continue;

        ++ans;
        current_end_time = inter[i].second;
    }
    cout << ans << endl;
}
