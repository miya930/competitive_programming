#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using Graph = vector<vector<int> >;

// ���́F�O���tG�ƁA�T���̎n�_ s
// �o�́Fs ����e���_�ւ̍ŒZ�H����\���z��
vector<int> BFS(const Graph& graph, int s) {
    int N = (int)G.size(); // ���_��
    vector<int> dist(N, -1); // �S���_���u���K��v�ɏ�����
    queue<int> que;

    // �������� (���_ 0 ���������_�Ƃ���)
    dist[0] = 0;
    que.push(0); // 0 ���F���_�Ƃ���.

    // BFS �J�n (�L���[����ɂȂ�܂ŒT�����s��)
    while (!que.empty()) {
        int v = que.front(); // �L���[����擪���_�����o��.
        que.pop();

        // v ���炽�ǂ�钸�_�����ׂĒ��ׂ�.
        for (int x : G[v]) {
            // ���łɔ����ς݂̒��_�͒T�����Ȃ�
            if (dist[x] != -1) continue;

            // �V���Ȕ��F���_ x �ɂ��ċ��������X�V���ăL���[�ɑ}��
            dist[x] = dist[v] + 1;
            que.push(x);
        }
    }
    return dist;
}

int main()
{
    // ���_���ƕӐ�
    int n, m;
    cin >> n >> m;

    // �O���t���͎�� (�����ł͖����O���t��z��)
    Graph G(n);
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // ���_ 0 ���n�_�Ƃ��� BFS
    vector<int> dist = BFS(G, 0);

    // ���ʏo�� (�e���_�̒��_ 0 ����̋���������)
    for (int v = 0; v < n; ++v) cout << v << ": " << dist[v] << endl;
}
