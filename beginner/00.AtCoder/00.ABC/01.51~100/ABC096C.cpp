// すべての'#'に対し隣接する'#'があるかチェック
// すべてあれば"Yes", なければ"No"を出力
#include <iostream>
#include <string>
using namespace std;

int main(void) 
{
    int H, W;
    cin >> H >> W;

    char S[100][100];
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> S[i][j];
        }
    }

    const int dx[4] = {1, 0, -1, 0};
    const int dy[4] = {0, 1, 0, -1};

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '.') continue;
            int num = 0; // 隣接する'#'の数をカウント

            for  (int d = 0; d < 4; d++) {
                const int ni = i + dx[d];
                const int nj = j + dy[d];

                if (ni < 0 || H <= ni) continue;
                if (nj < 0 || W <= nj) continue;
                if (S[ni][nj] == '#') num++;
            }
            if (!num) {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;
    
    return 0;
}
