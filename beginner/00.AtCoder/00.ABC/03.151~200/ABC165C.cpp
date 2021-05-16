#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int N, M, Q;
vector<ll> a, b, c, d;

ll score(const vector<int> &A)
{
    ll res = 0;
    for (int i = 0; i < Q; i++) if (A[b[i]] - A[a[i]] == c[i]) res += d[i];
    return res;
}

ll dfs(vector<int> &A)
{
    if (A.size() == N) {
        return score(A);
    }
    ll res = 0;
    int prev_last = (A.empty() ? 0 : A.back());
    for (int i = prev_last; i < M; i++) {
        A.push_back(i);
        res = max(res, dfs(A));
        A.pop_back();
    }
    return res;
}

int main(void)
{
    cin >> N >> M >> Q;
    a.resize(Q); b.resize(Q); c.resize(Q); d.resize(Q);
    for (int q = 0; q < Q; q++) {
        cin >> a[q] >> b[q] >> c[q] >> d[q];
        --a[q], --b[q];
    }
    vector<int> A;
    cout << dfs(A) << endl;
}
