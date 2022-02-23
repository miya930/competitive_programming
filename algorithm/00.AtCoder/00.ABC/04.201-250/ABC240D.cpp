#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<pair<int,int>> vec;
    
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        cnt += 1;
        if (vec.empty() || vec.back().first != a) {
            vec.push_back({a, 1});
        } else {
            vec.back().second += 1;
            if (vec.back().second == a) {
                cnt -= a;
                vec.pop_back();
            }
        }
        cout << cnt << endl;
    }

    return 0;
}
