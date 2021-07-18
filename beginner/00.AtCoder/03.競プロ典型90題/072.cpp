#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int h, w;
char c[20][20];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool used[20][20];

int dfs(int sx, int sy, int px, int py) { // sx, sy�F�X�^�[�g�̍��W�Apx, py�F�S�[���̍��W
    if (sx == px && sy == py && used[px][py] == true) return 0; 
    used[px][py] = true;

    int ret = -10000;
    for (int i = 0; i < 4; i++) {
        int nx = px + dx[i], ny = py + dy[i];
        if (nx < 1 || ny < 1 || nx > h || ny > w || c[nx][ny] == '#') continue;
        if ((sx != nx || sy != ny) && used[nx][ny] == true) continue; // �T���ς݂̒��_�̏ꍇ�i�������X�^�[�g�n�_�͏���)
        int v = dfs(sx, sy, nx, ny);
        ret = max(ret, v + 1);
    }
    used[px][py] = false;
    return ret;
}

int main()
{
    cin >> h >> w;
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) cin >> c[i][j];
    }

    int answer = -1;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; ++j) {
            answer = max(answer, dfs(i, j, i, j));
        }
    }
    if (answer <= 2) answer = -1;
    cout << answer << endl;
    
    return 0;

    

}
