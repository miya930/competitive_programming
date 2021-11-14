#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    int N, M, Q;
    cin >> N >> M >> Q;

    vector<pair<int, int> > vec(N);

    for (int i = 0; i < N; ++i) {
        cin >> vec[i].second >> vec[i].first;
    }
    sort(vec.rbegin(), vec.rend());

    vector<int> X(M);
    for (int i = 0; i < M; i++) cin >> X[i];

    for (int q = 0; q < Q; q++) {
        int l, r; cin >> l >> r;
        l--; r--;
        int ans = 0;
        vector<pair<int, bool> > temp;
        for (int i = 0; i < l; ++i) temp.push_back(make_pair(X[i], true));
        for (int i = r + 1; i < M; ++i) temp.push_back(make_pair(X[i], true));
        sort(temp.begin(), temp.end());

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < (int)temp.size(); ++j) {
                if (temp[j].second == false) continue;
                if (vec[i].second > temp[j].first) continue;
                if (temp[j].second == true) {
                    ans += vec[i].first;
                    temp[j].second = false;
                    break;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
