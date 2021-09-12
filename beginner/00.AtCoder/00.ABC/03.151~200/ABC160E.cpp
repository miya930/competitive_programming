/**
 * 方針
 * A, B個の着色済みのリンゴをおいしさの高い順にソートして、それぞれ上からX, Y個選んで別の配列に入れて昇順にソートする
 * 無職のリンゴのおいしさと比較していく。
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    vector<int> p(a), q(b);

    priority_queue<int> que;
    
    rep(i, a) cin >> p[i];
    rep(i, b) cin >> q[i];
    rep(i, c) {
        int r; cin >> r;
        que.push(r);
    }

    sort(p.rbegin(), p.rend());
    sort(q.rbegin(), q.rend());

    vector<int> vec;
    rep(i, x) vec.push_back(p[i]);
    rep(i, y) vec.push_back(q[i]);

    sort(vec.begin(), vec.end());

    for (int i = 0; i < c; ++i) {
        if (vec[i] < que.top()) {
            vec[i] = que.top();
            que.pop();
        } else {
            break;
        }
    }

    long long ans = 0;
    rep(i, (int)vec.size()) {
        ans += vec[i];
    }

    cout << ans << endl;
}
