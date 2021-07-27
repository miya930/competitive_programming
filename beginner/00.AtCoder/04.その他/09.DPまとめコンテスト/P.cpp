#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<vector<int> > Graph;
const int mod = 1000000007;

vector<vector<long long> > dp;          // dp[i][j]�F���_i�����Ƃ���F�̑g�ݍ��킹�̑���. j�͐F��\�� (0�F��, 1�F��)
vector<bool> seen;

void dfs(const Graph& G, int v) {
    seen[v] = true;

    for (auto nv : G[v]) {              // �T���ς݂łȂ��q���_�݂̂ɂ��ĐF�̑g�ݍ��킹���v�Z����������
        if (seen[nv] == true) continue;
        dfs(G, nv);
        dp[v][0] = dp[v][0] * (dp[nv][0] + dp[nv][1]) % mod;
        dp[v][1] = dp[v][1] * dp[nv][0] % mod;
    }

    /**
     * ������dp�̏����������Ǝq���_�݂̂łȂ��e���_�ɂ��Ă��F�̑g�ݍ��킹�̌v�Z�ɓ���Ă��܂����߁A���ʂ��Ԉ���Ă��܂��B
     */

}

int main()
{
    int n;
    cin >> n;
    Graph G(n);
    for (int i = 0; i < n-1; ++i) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    dp.assign(n+1, vector<long long>(2, 1));
    seen.assign(n, false);

    dfs(G, 0);

    cout << (dp[0][0] + dp[0][1]) % mod << endl;
}
