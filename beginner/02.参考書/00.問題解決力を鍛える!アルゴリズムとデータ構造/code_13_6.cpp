#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using Graph = vector<vector<int> >;

// �g�|���W�J���\�[�g����
vector<bool> seen;
vector<int> order; // �g�|���W�J���\�[�g����\��
void rec(const Graph &G, int v) {
    seen[v] = true;
    for (auto next_v : G[v]) {
        if (seen[next_v]) continue;
        rec(G, next_v);
    }

    // v-out ���L�^����. (���������ɔz��ɋL�^�����)
    order.push_back(v);
}

int main()
{
    int n, m;
    cin >> n >> m;
    Graph G(n); // ���_���ƕӐ�
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }

    // �T��
    seen.assign(n, false); // ������Ԃł͑S���_�����K��
    order.clear(); // �g�|���W�J���\�[�g��
    for (int v = 0; v < n; ++v) {
        if (seen[v]) continue;
        rec(G, v);
    }
    reverse(order.begin(), order.end()); // �t����

    // �o��
    for (auto v : order) cout << v << " -> ";
    cout << endl;
}
