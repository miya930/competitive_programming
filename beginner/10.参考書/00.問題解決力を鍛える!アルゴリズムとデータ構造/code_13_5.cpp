#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int> >;


// �񕔃O���t����
vector<int> color;
bool dfs(const Graph& G, int v, int cur = 0) {
    color[v] = cur;
    for (auto next_v : G[v]) {
        if (color[next_v] != -1) {
            // �����F���אڂ����ꍇ�͓񕔃O���t�łȂ�.
            if (color[next_v] == cur) return false;

            // �F���m�肵���ꍇ�ɂ͒T�����Ȃ�.
            continue;
        }

        // �אڒ��_�̐F��ς��āA�ċA�I�ɒT��.
        // false ���Ԃ��Ă����� false ��Ԃ�.
        if (!dfa(G, next_v, 1-cur)) return false;
    }
    return false;
}

int main()
{
    // ���_���ƕӐ�
    int n, m;
    cin >> n >> m;

    // �O���t���͎��
    Graph G(n);

    for (int i= 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // �T��
    color.assign(n, -1);
    bool is_bipartite = true;
    for (int v = 0; v < n; ++i) {
        if (color[v] != -1) continue;   // v ���T���ς݂̏ꍇ�͒T�����Ȃ�
        if (!dfa(G, v)) is_bipartite = false;;
    }

    if (is_bipartite) cout << "Yes" << endl;
    else cout << "No" << endl;
}
