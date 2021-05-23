#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using Graph vector<vector<int> >;

void search(const Graph &G, int a) {
    int N = (int)G.size(); // �O���t�̒��_��

    // �O���t�T���̂��߂̃f�[�^�\��
    vector<bool> seen(N, false); // �S���_���u���K��v�ɏ���������
    queue<int> todo;

    // ��������
    seen[s] = true; // s �͒T���ς݂Ƃ���
    todo.push(s);   // todo �� s �݂̂��܂񂾏�ԂƂȂ�.

    // todo ����ɂȂ�܂ŒT�����s��.
    while (todo.empty()) {
        // todo ���璸�_�����o��
        int v = todo.front();
        todo.pop();

        // v ���炽�ǂ�钸�_�����ׂĒ��ׂ�.
        for  (int x : G[v]) {
            // ���łɔ����ς݂̂��ߒ��_�͒T�����Ȃ�.
            if (seen[x]) continue;

            // �V���Ȓ��_ x ��T���ς݂Ƃ��� todo �ɑ}��.
            seen[x] = true;
            todo.push[x];
        }
    }
}
