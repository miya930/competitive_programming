#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001001;

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

/// @brief 各セルの接続状態を管理するためのデータ構造
struct UnionFind {
    vector<int> par, siz;

    void init(int n) {
        par.assign(n, -1);
        siz.assign(n, 1);
    }

    int root(int x) {
        if (par[x] == -1) return x;
        else return par[x] = root(par[x]);
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool unite(int x, int y) {
        x = root(x); y = root(y);

        if (x == y) return false;

        if (siz[x] < siz[y]) swap(x, y);

        par[y] = x;
        siz[x] += siz[y];
        return true;
    }

    int size(int x) {
        return siz[root(x)];
    }

};

/*************************************************
 * コンテスト
 *************************************************/
using PP = pair<int, pair<int,int>>;
struct Pos {
    int x, y;
};

vector<vector<int>> sturdiness(210, vector<int>(210));
vector<vector<int>> connect_to_source(210, vector<int>(210, 0));
vector<int> isfinish(50, 0);
ofstream ofs("test.csv");

priority_queue<PP, vector<PP>, greater<PP>> que;

/* UnionFind上で管理する番号 (x, y座標から1次元に変換した情報)と各家、水源のIDを紐づけるための辞書 */
map<int,int> house_ufid2id;
map<int,int> house_id2ufid;
map<int,int> source_ufid2id;
map<int,int> source_id2ufid;

int sum = 0;
int last_sturdiness;
int sturdiness_error = 0;

UnionFind uf;
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

#define TEST    (0)

enum class Response {
    not_broken, broken, finish, invalid
};

struct Field {
    int N;
    int C;
    int K;
    int W;
    vector<vector<int>> isbroken;
    vector<Pos> source_pos;
    int total_cost = 0;
    int sum = 0;

    Field(int N, int C, int K, int W, vector<Pos> source_pos): N(N), C(C), K(K), W(W), isbroken(N, vector<int>(N, 0)), source_pos(source_pos)  {};

    Response query(int y, int x, int power, Pos start) {
        sum += power;
        total_cost += power + C;
        int r = 0;
        cout << y << " " << x << " " << power << endl;

        int now_ufid = N*y + x;
        int start_ufid = N*start.y + start.x;

#if TEST
        ofs << y << " " << x << " " << power << endl;
        sturdiness[y][x] -= power;

        if (sturdiness[y][x] <= 0) {

            /* 岩石の硬さの勾配を計算 */
            sturdiness_error = sum - last_sturdiness;
            last_sturdiness = sum;
            sum = 0;

            sturdiness[y][x] = 0;
            isbroken[y][x] = true;
            r = 1;

            /* 同じグループにする */
            uf.unite(now_ufid, start_ufid);
            if (connect_to_source[start.y][start.x]) {
                connect_to_source[y][x] = true;
                if (house_ufid2id.count(now_ufid)) {
                    isfinish[house_ufid2id[now_ufid]] = true;
                }
            }

            SetFinishFlag(y, x, start);

            /* 岩石破壊後につながっている場合があるため */
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                if (isbroken[ny][nx]) {
                    int ufid = N*ny + nx;
                    uf.unite(ufid, start_ufid);
                    SetFinishFlag(ny, nx, start);
                }
            }
            if (isDone()) r = 2;
        }
#else
        cin >> r;
#endif
        switch(r) {
            case 0:
                return Response::not_broken;
            case 1:
                isbroken[y][x] = 1;
#if !TEST

                /* 同じグループにする */
                uf.unite(now_ufid, start_ufid);
                if (connect_to_source[start.y][start.x]) {
                    connect_to_source[y][x] = true;
                    if (house_ufid2id.count(now_ufid)) {
                        isfinish[house_ufid2id[now_ufid]] = true;
                    }
                }

                SetFinishFlag(y, x, start);

                /* 岩石破壊後につながっている場合があるため */
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    if (isbroken[ny][nx]) {
                        int ufid = N*ny + nx;
                        uf.unite(ufid, start_ufid);
                        SetFinishFlag(ny, nx, start);
                    }
                }
#endif
                return Response::broken;
            case 2:
                isbroken[y][x] = 1;
                return Response::finish;
            default:
                return Response::invalid;
        }
    }

    /// @brief 全ての家が水源と接続済みであればtrueを返す
    /// @return isFinish: すべての水源と接続されたら 
    bool isDone() {
        int house_num = K;

        bool isFinish = true;
        for (int house_id = 0; house_id < house_num; house_id++) {
            if (!isfinish[house_id]) {
                isFinish = false;
            }
        }
        return isFinish;
    }

    /// @brief 新たに水源と接続されたすべての家に対して、接続済みのフラグを立てる
    /// @param 
    /// @param 
    void SetFinishFlag(int y, int x, Pos start) {
        // UnionFindでグループに分けられているので、水源と同じグループか確認して同じであればBFSで廉潔な全ての頂点のconnnect_to_source = trueにする
        int now_ufid = N*y + x;

        for (int source = 0; source < W; source++) {
            int source_ufid = N * source_pos[source].y + source_pos[source].x;
            if (uf.issame(now_ufid, source_ufid)) {
                if (!connect_to_source[y][x] || !connect_to_source[start.y][start.x]) {
                    SetConnectBfs(y, x);
                }
            }
        }
    }

    /// y, xをスタート地点とし接続されている全ての岩石破壊済みのセルに対して、水源と接続済みのフラグを立てる.
    void SetConnectBfs(int y, int x) {
        queue<pair<int,int>> que;
        vector<vector<int>> seen(N, vector<int>(N, 0));
        que.push(make_pair(y, x));
        seen[y][x] = true;

        /* スタート地点が家であればisfinishフラグを立てる */
        int ufid = y*N + x;
        if (house_ufid2id.count(ufid)) {
            int id = house_ufid2id[ufid];
            isfinish[id] = true;
        }

        while(!que.empty()) {
            int vy = que.front().first;
            int vx = que.front().second;
            que.pop();

            for (int i = 0; i < 4; i++) {
                int ny = vy + dy[i];
                int nx = vx + dx[i];

                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                /* 岩石破壊済みでなければパス */
                if (!isbroken[ny][nx]) continue;
                if (seen[ny][nx]) continue;

                /* nx, nyが家であればisfinishフラグを立てる */
                int n_ufid = ny*N + nx;
                if (house_ufid2id.count(n_ufid)) {
                    int n_id = house_ufid2id[n_ufid];
                    isfinish[n_id] = true;
                }

                connect_to_source[ny][nx] = 1;
                seen[ny][nx] = true;
                que.push(make_pair(ny, nx));
            }
        }
    }

    void OutputConnect() {
        ofs << endl;
        ofs << endl;
        /* for debug */
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (connect_to_source[i][j] == 0) ofs << '.';
                else ofs << '@';
            }

            ofs << endl;
        }
    }
};

struct Solver {
    int N;
    int C;
    int K;
    int W;
    vector<Pos> source_pos, house_pos;
    vector<vector<int>> house_map, source_map;
    vector<vector<int>> dist;
    Field field;

    Pos goal_pos;

    Solver(int N, int C, int K, int W,const vector<Pos>& source_pos, vector<Pos>& house_pos, vector<vector<int>>& source_map, vector<vector<int>>& house_map):
        N(N), K(K), W(W), source_pos(source_pos), house_pos(house_pos), C(C), field(N, C, K, W, source_pos), dist(N,vector<int>(N, -1)), house_map(N, vector<int>(N, -1)), source_map(N, vector<int>(N, 0)) {}

    void solve() {
        ofstream ofs("test.csv");

        /// 接続していない頂点のうちで最も近い頂点と接続する.
        int cnt = 0;
        while(1) {
            krascalmod();
        }

        // should receive Response::finish and exit before entering here
        assert(false);
    }

    void krascalmod() {
        // 短い辺を順番に接続していく
        // 家同士の最短距離
        for (int i = 0; i < K; i++) {
            for (int j = 0; j < K; j++) {
                if (i == j) continue;
                int dis = abs(house_pos[i].x - house_pos[j].x) + abs(house_pos[i].y - house_pos[j].y);
                que.push(make_pair(dis, make_pair(N*house_pos[i].y + house_pos[i].x, N*house_pos[j].y + house_pos[j].x)));
            }
        }

        // 家と水源の最短距離
        for (int i = 0; i < W; i++) {
            for (int j = 0; j < K; j++) {
                int dis = abs(source_pos[i].x - house_pos[j].x) + abs(source_pos[i].y - house_pos[j].y);
                que.push(make_pair(dis, make_pair(N*source_pos[i].y+source_pos[i].x, N*house_pos[j].y+house_pos[j].x)));
            }
        }

        vector<vector<bool>> visit(N, vector<bool>(N, false));
        while(1) {
            // 辺を接続する。接続後、BFSしながら各頂点との最短距離を求める
            // 求めた各頂点との最短距離をqueに入れていく。
            int dis = que.top().first;
            int v1_ufid = que.top().second.first;
            int v2_ufid = que.top().second.second;
            que.pop();

            /* 接続済みであればパス */
            if (uf.issame(v1_ufid, v2_ufid)) continue;
            if (source_ufid2id.count(v1_ufid)) swap(v1_ufid, v2_ufid);

            /* 頂点座標を求める */
            int v1y = v1_ufid / N;
            int v1x = v1_ufid % N;
            int v2y = v2_ufid / N;
            int v2x = v2_ufid % N;

            /* 両方とも水源と接続済みであればパス */
            if (connect_to_source[v1y][v1x] && connect_to_source[v2y][v2x]) continue;

            Pos s, g;
            s.y = v1y;
            s.x = v1x;
            g.y = v2y;
            g.x = v2x;

            move2(s, g);

            /* 移動中と各頂点との最短距離を求めて、priority_queueに格納する */
            BfsConnect(visit, que, v1y, v1x);
        }
    }

    void BfsConnect(vector<vector<bool>> &vis, priority_queue<PP, vector<PP>, greater<PP>> p_que, int y, int x) {
        vis[y][x] = true;
        queue<pair<int,int>> que;
        que.push(make_pair(y, x));

        while(!que.empty()) {
            int vy = que.front().first;
            int vx = que.front().second;
            que.pop();

            for (int i = 0; i < 4; i++) {
                int nx = vx + dx[i];
                int ny = vy + dy[i];

                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                if (vis[ny][nx]) continue;

                vis[ny][nx] = true;
                que.push(make_pair(ny, nx));

                /* 各水源、家との最短距離を求める */
                for (int j = 0; j < K; j++) {
                    int diff = abs(nx - house_pos[j].x) + abs(ny - house_pos[j].y);
                    p_que.push(make_pair(diff, make_pair(N*ny + nx, N*house_pos[j].y + house_pos[j].x)));
                }
                for (int j = 0; j < W; j++) {
                    int diff = abs(nx - source_pos[j].x) + abs(ny - source_pos[j].y);
                    p_que.push(make_pair(diff, make_pair(N*ny + nx, N*source_pos[j].y + source_pos[j].x)));
                }
            }
        }
    }

    /* start, goalを最短経路で接続する */
    void move(Pos start, Pos goal) {
        int start_ufid = start.y * N + start.x;
        int goal_ufid = goal.y * N + goal.x;
        // down/up
        if (start.y < goal.y) {
            for (int y = start.y; y < goal.y; y++) {
                if (uf.issame(start_ufid, goal_ufid)) break;
                destruct(y, start.x, start);
            }
        } else {
            for (int y = start.y; y > goal.y; y--) {
                if (uf.issame(start_ufid, goal_ufid)) break;
                destruct(y, start.x, start);            
            }
        }

        // right/left
        if (start.x < goal.x) {
            for (int x = start.x; x <= goal.x; x++) {
                if (uf.issame(start_ufid, goal_ufid)) break;
                destruct(goal.y, x, start);           
            }
        } else {
            for (int x = start.x; x >= goal.x; x--) {
                if (uf.issame(start_ufid, goal_ufid)) break;
                destruct(goal.y, x, start);
            }
        }
    }

    /* start, goalを最短経路で接続する */
    void move2(Pos start, Pos goal) {
        int start_ufid = start.y * N + start.x;
        int goal_ufid = goal.y * N + goal.x;
        int direction = 0;  /* default: y方向 */

        /* 岩石の硬さの勾配が400を超えたら、進行方向を変える.
         * 変えるルールは以下とする.
         * - 例えばy方向からx方向に変える場合、目標地点の座標との差分が1以上の時は変える。
         *   そうでないときは進行方向を変えない (後で差分がない場合もランダムに+-どちらに進むかを決めて10マス移動するを試す) */
        Pos cur = start;
        bool isfirst = true;
        int count = 0;

        /* reset gradient infomation */
        sum = 0;
        last_sturdiness = 0;
        sturdiness_error = 0;

        while(!uf.issame(start_ufid, goal_ufid)) {
            if (direction == 0) {
                // down/up
                while(1) {
                    if (uf.issame(start_ufid, goal_ufid)) break;
                    destruct(cur.y, cur.x, start);
//                    isfirst = false;
                    count++;

                    /* 移動 */
                    if (cur.y < goal.y) cur.y++;
                    else if (cur.y > goal.y) cur.y--;
                    else {
                        direction = 1;
                        count = 0;
                        break;
                    }

                    if (cur.x != goal.x && sturdiness_error > 250 && count > 3) {
                        direction = 1;
                        count = 0;
                        break;
                    }
                }
            } else {
                while(1) {
                    if (uf.issame(start_ufid, goal_ufid)) break;
                    destruct(cur.y, cur.x, start);
//                    isfirst = false;
                    count++;

                    /* 移動 */
                    if (cur.x < goal.x) cur.x++;
                    else if (cur.x > goal.x) cur.x--;
                    else {
                        direction = 0;
                        count = 0;
                        break;
                    }

                    if (cur.y != goal.y && sturdiness_error > 250 && count > 3) {
                        direction = 0;
                        count = 0;
                        break;
                    }
                }
            }
        }
    }

    void destruct(int y, int x, Pos start) {
        // excavate (y, x) with fixed power until destruction
        const int power = 100;
        while (!field.isbroken[y][x]) {
            Response result = field.query(y, x, power, start);
            if (result == Response::finish) {
                cerr << "total_cost=" << field.total_cost << endl;
                exit(0);
            } else if (result == Response::invalid) {
                cerr << "invalid: y=" << y << " x=" << x << endl;
                exit(1);
            } 
        }
    }
};

int main()
{
    int N, W, K, C;
    cin >> N >> W >> K >> C;
    vector<Pos> source_pos(W);
    vector<Pos> house_pos(K);
    vector<vector<int>> house_map(N, vector<int>(N, -1)), source_map(N, vector<int>(N, -1));

#if TEST
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> sturdiness[i][j];
        }
    }
#endif

    for (int i = 0; i < W; i++) {
        int y, x;
        cin >> y >> x;
        source_ufid2id[y*N+x] = i;
        source_id2ufid[i] = y*N + x;
        source_map[y][x] = i;
        source_pos[i].x = x;
        source_pos[i].y = y;
        connect_to_source[y][x] = 1;
    }

    for (int i = 0; i < K; i++) {
        int x, y;
        cin >> y >> x;
        house_ufid2id[y*N+x] = i;
        house_id2ufid[i] = y*N + x;
        house_map[y][x] = i;
        house_pos[i].x = x;
        house_pos[i].y = y;
    }

    /* マスの接続状態を管理 */
    uf.init(N*N);

    Solver solver(N, C, K, W, source_pos, house_pos, source_map, house_map);
    solver.solve();

    return 0;
}

