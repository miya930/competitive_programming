#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int H, W;
    cin >> H >> W;

    string S[100];
    for (int i = 0; i < H; i++) cin >> S[i];

    const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
    const int dy[8] = {0, 1,  0, -1, 1, -1, 1, -1};

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '#') continue;

            int num = 0;
            for (int d = 0; d < 8; d++) {
                const int ni = i + dx[d];
                const int nj = j + dy[d];

                if (ni < 0 || H <= ni) continue;
                if (nj < 0 || W <= nj) continue;
                if (S[ni][nj] == '#') num++;
            }
            S[i][j] = char(num + '0');
        }
    }

    for (int i = 0; i < H; i++) cout << S[i] << endl;

    return 0;
}
