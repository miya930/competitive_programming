#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*************************************************
 * 時間測定
 *************************************************/
using TimePoint = chrono::high_resolution_clock::time_point;

struct CTimer {
private:
    TimePoint startTime_;
    TimePoint endTime_;
public:
    inline void Init() {
        startTime_ = chrono::high_resolution_clock::now();
        endTime_ = startTime_;
    }

    inline void Start(int endtime) {
        endTime_ = startTime_ + chrono::microseconds(endtime);
    }

    inline bool IsOver() {
        return (chrono::high_resolution_clock::now() >= endTime_);
    }

    inline int ElapsedTime() {
        return (chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now() - startTime_).count() * 1e-6);
    }

    inline int LeftTime(const TimePoint endTime) {
        return (chrono::duration_cast<chrono::microseconds>(endTime - chrono::high_resolution_clock::now()).count() * 1e-6);
    }

};


/*************************************************
 * コンテスト
 *************************************************/
struct Field {
private:
    int d;
public:
    vector<string> f;
    vector<string> r;
    vector<vector<int>> fnum;   /* front sideから見て何個のブロックが存在するか */
    vector<vector<int>> rnum;   /* right sideから見て何個のブロックが存在するか */

    void Init(int d) {
        fnum.assign(d, vector<int>(d, 0));
        rnum.assign(d, vector<int>(d, 0));
    }
};

struct Cube {
    int x;
    int y;
    int z;
};

int D = 0, N = 0;
vector<map<int, Cube>> cubes(2);
int dx[] = {1, -1, 0,  0, 0, 0};
int dy[] = {0,  0, 1, -1, 0, 0};
int dz[] = {0,  0, 0,  0, 1, -1};

struct Solver {
private:
    int d;
public:
    Field field[2];
    int answer[2][15*15*15];
    int flg[2][15][15][15];
    int sz[2][15*15*15];

    /// @brief 入力の受け取り
    /// @param  
    void input(void) {
        cin >> D;

        for (int c = 0; c < 2; c++) {
            /* front side (x-z plane) */
            for (int i = 0; i < D; i++) {
                string s;
                cin >> s;

                field[c].f.push_back(s);
            }

            /* right side (y-z plane) */
            for (int i = 0; i < D; i++) {
                string s;
                cin >> s;

                field[c].r.push_back(s);
            }
        }

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 15*15*15; j++) {
                answer[i][j] = 0;
                sz[i][j] = 0;
            }
        }

        for (int x = 0; x < 15; x++) {
            for (int y = 0; y < 15; y++) {
                for (int z = 0; z < 15; z++) {
                    flg[0][x][y][z] = 0;
                    flg[1][x][y][z] = 0;
                }
            }
        }

        field[0].Init(D);
        field[1].Init(D);
   
    }

    /// @brief 出力処理
    /// @param  
    void output(void) {
        cout << N << endl;
        for (int c = 0; c < 2; c++) {
            for (int i = 0; i < D*D*D; i++) {
                cout << answer[c][i] << " ";
            }
            cout << endl;
        }
    }

    /// @brief ブロックを置いてよいかどうかを判定する
    /// @param c 1 or 2
    /// @param x 
    /// @param y 
    /// @param z 
    /// @return 
    bool canput(int c, int x, int y, int z) {
        bool ret = false;

        if (field[c].f[z][x] == '1' && field[c].r[z][y] == '1') {
            ret = true;
        }

        return ret;
    }

    /// @brief とりあえず全て1×1×1のキューブで埋めた場合の解
    /// @param  
    void solve_allcube(void) {
        for (int i = 0; i < 2; i++) {
            int cur = 0;            
            for (int x = 0; x < D; x++) {
                for (int y = 0; y < D; y++) {
                    for (int z = 0; z < D; z++) {
                        if (field[i].f[z][x] == '1' &&field[i].r[z][y] == '1') {
                            cur++;
                            answer[i][x*D*D+y*D+z] = cur;
                        }
                    }
                }
            }
            N = max(N, cur);
        }
    }

    /// @brief メイン処理 (初回提出). とりあえず全て1×1×1から、不要なものを除去
    /// @param  
    void solve2(void) {
        for (int i = 0; i < 2; i++) {
            int cur = 0;            
            for (int x = 0; x < D; x++) {
                for (int y = 0; y < D; y++) {
                    for (int z = 0; z < D; z++) {
                        if (canput(i, x, y, z)) {

                            /* 既にキューブがあるならスキップ */
                            if (field[i].fnum[z][x] > 0 && field[i].rnum[z][y] > 0) continue;

                            cur++;
                            answer[i][x*D*D+y*D+z] = cur;

                            /* 直線状にあるキューブの数 */
                            field[i].fnum[z][x]++;
                            field[i].rnum[z][y]++;
                        }
                    }
                }
            }
            N = max(N, cur);
        }
    }

    /// @brief メイン処理. 隣り合うブロックで連結できるものは連結していく
    /// @param  
    void solve3(void) {

        /// cubeをおいていく処理
        for (int i = 0; i < 2; i++) {
            int cur = 0;            
            for (int x = 0; x < D; x++) {
                for (int y = 0; y < D; y++) {
                    for (int z = 0; z < D; z++) {
                        if (canput(i, x, y, z)) {

                            /* 既にキューブがあるならスキップ */
                            if (field[i].fnum[z][x] > 0 && field[i].rnum[z][y] > 0) continue;

                            cur++;
                            answer[i][x*D*D+y*D+z] = cur;
                            flg[i][x][y][z] = cur;
                            sz[i][x*D*D+y*D+z] = 1;

                            cubes[i][cur].x = x;
                            cubes[i][cur].y = y;
                            cubes[i][cur].z = z;

                            /* 直線状にあるキューブの数 */
                            field[i].fnum[z][x]++;
                            field[i].rnum[z][y]++;
                        }
                    }
                }
            }
            N = max(N, cur);
        }

        /// 隣同士の1×1×1のcubeを結合してサイズ2のものにする
        for (int c = 1; c <= N; c++) {
            int x  = cubes[0][c].x;
            int y  = cubes[0][c].y;
            int z  = cubes[0][c].z;

            if (x == -1 || y == -1 || z == -1) continue;

            for (int i = 0; i < 6; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                int nz = z + dz[i];

                if (nx < 0 || nx >= D || ny < 0 || ny >= D || nz < 0 || nz >= D) continue;

                // cubeが置かれていてかつサイズが1なら結合できる
                if (flg[0][nx][ny][nz] != 0 && sz[0][nx*D*D+ny*D+nz] == 1 && sz[0][x*D*D+y*D+z] == 1) {
                    /// 2の方で探す
                    int x2  = cubes[1][c].x;
                    int y2  = cubes[1][c].y;
                    int z2  = cubes[1][c].z;

                    if (x2 == -1 || y2 == -1 || z2 == -1) continue;

                    for (int j = 0; j < 6; j++) {
                        int nx2 = x2 + dx[j];
                        int ny2 = y2 + dy[j];
                        int nz2 = z2 + dz[j];

                        if (nx2 < 0 || nx2 >= D || ny2 < 0 || ny2 >= D || nz2 < 0 || nz2 >= D) continue;

                        if (flg[1][nx2][ny2][nz2] != 0 && sz[1][nx2*D*D+ny2*D+nz2] == 1 && sz[1][x2*D*D+y2*D+z2] == 1) {
                            int tmp = flg[0][nx][ny][nz];
                            int tmp2 = flg[1][nx2][ny2][nz2];

                            if (c == 1) {
                                int dummy = 1;
                            } else if (c == 4) {
                                int dummy = 1;
                            }

                            int x3 = cubes[1][tmp].x;
                            int y3 = cubes[1][tmp].y;
                            int z3 = cubes[1][tmp].z;

                            flg[0][nx][ny][nz] = flg[0][x][y][z];           // flg[0][x][y][z] == flg[1][x2][y2][z2]
                            flg[1][nx2][ny2][nz2] = flg[1][x2][y2][z2];
                            flg[1][x3][y3][z3] = tmp2;
                            sz[0][nx*D*D+ny*D+nz] = 2;
                            sz[0][x*D*D+y*D+z] = 2;
                            sz[1][nx2*D*D+ny2*D+nz2] = 2;
                            sz[1][x2*D*D+y2*D+z2] = 2;

                            cubes[0][tmp].x = -1;
                            cubes[0][tmp].y = -1;
                            cubes[0][tmp].z = -1;
                            cubes[1][tmp].x = -1;
                            cubes[1][tmp].y = -1;
                            cubes[1][tmp].z = -1;

                        }
                    }
                }
            }
        }

        queue<int> que;
        for (int i = 1; i <= N; i++) {
            int x = cubes[0][i].x;
            if (x == -1) continue;
            que.push(i);
        }

        for (int i = 0; i < D*D*D; i++) {
            answer[0][i] = 0;
            answer[1][i] = 0;
        }

        int cur = 1;

        while(!que.empty()){
            int num = que.front();
            que.pop();

            int x = cubes[0][num].x;
            int y = cubes[0][num].y;
            int z = cubes[0][num].z;
            answer[0][x*D*D+y*D+z] = cur;

            int x2 = cubes[1][num].x;
            int y2 = cubes[1][num].y;
            int z2 = cubes[1][num].z;
            answer[1][x2*D*D+y2*D+z2] = cur;

            for (int i = 0; i < 6; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                int nz = z + dz[i];

                if (nx < 0 || nx >= D || ny < 0 || ny >= D || nz < 0 || nz >= D) continue;

                if (flg[0][nx][ny][nz] == num) {
                    answer[0][nx*D*D+ny*D+nz] = cur;
                }

                int nx2 = x2 + dx[i];
                int ny2 = y2 + dy[i];
                int nz2 = z2 + dz[i];
                
                if (nx2 < 0 || nx2 >= D || ny2 < 0 || ny2 >= D || nz2 < 0 || nz2 >= D) continue;
            
                if (flg[1][nx2][ny2][nz2] == num) {
                    answer[1][nx2*D*D+ny2*D+nz2] = cur;
                }

            }

            cur++;
        }

        N = cur - 1;
    }

};


int main()
{
    Solver solver;

    solver.input();
    solver.solve3();
    solver.output();


    return 0;
}
