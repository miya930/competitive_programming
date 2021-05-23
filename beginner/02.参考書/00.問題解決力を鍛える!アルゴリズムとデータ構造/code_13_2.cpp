#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int> >;

// �[���D��T��
vector<bool> seen;
void dfs(const Graph &G, int v) {
    seen[v] = true;     // v ��K��ς݂ɂ���.

    // v ���炢����e���_ next_v �ɂ���
    for (auto next_v : G[v]) {
        if (seen[next_v]) continue; // next_v ���T���ς݂Ȃ�T�����Ȃ�.
        dfs(G, next_v);
    }
}

int main()
{
    // ���_���ƕӐ�
    int n, m;
    cin >> n >> m;

    // �O���t���͎�� (�����ł͗L���O���t��z��)
    Graph G(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }

    // �T��
    seen.assign(n, false);
    for (int v = 0; v < n; ++i) {
        if (seen[v]) continue;
        dfs(G, v);
    }
}
