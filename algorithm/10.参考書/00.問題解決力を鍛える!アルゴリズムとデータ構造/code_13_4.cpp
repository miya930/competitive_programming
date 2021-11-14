#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using Graph = vector<vector<int> >;

vector<bool> seen;
void dfa(const Graph &G, int v) {
    seen[v] = true; // v ��K��ςɂ���

    // v ����
    for (auto next_v : G[v]) {
        if (seen[next_v]) continue; // next_v ���T���ςȂ�ΒT�����Ȃ�
        dfa(G, next_v); // �ċA�I�ɒT��
    }
}

int main() {
    // ���_���ƕӐ��As �� t
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    
    // �O���t���͎��
    Graph G(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }

    // ���_ a ���X�^�[�g�Ƃ����T��
    seen.assign(n, false); // �S���_���u���K��v�ɏ�����
    dfa(G, a);

    // t �ɂ��ǂ蒅���邩
    if (seen[t]) cout << "Yes" << endl;
    else cout << "No" << endl;
}
