#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,int>;
const ll infl = 1LL << 60;

struct edge {
    int to;
    ll w;
};
using Graph = vector<vector<edge>>;

#define DEBUG   (0)

Graph G(1050);
vector<Graph> Gk(40, Graph(1050));

/// @brief 工事しない場合の最短距離
vector<ll> dist(1050, infl);
/// @brief 工事する場合の最短距離. 
vector<ll> disbuf(1050,  infl);
/// @brief 各頂点の座標
vector<pair<int,int>> pos;
vector<int> anssum(40, 0);
map<int,P> mp;
map<pair<int,int>, int> mpidx;

vector<int> ans(3100), scores;
int N, M, D, K, Count = 700;
double score;

/// @brief 入力処理
/// @param  
void Input(void) {
    cin >> N >> M >> D >> K;

    for (int i = 0; i < M; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--; v--;
        mp[i] = P(u, v);

        G[u].push_back(edge{v, w});
        G[v].push_back(edge{u, w});

        mpidx[make_pair(u, v)] = G[u].size() - 1;
        mpidx[make_pair(v, u)] = G[v].size() - 1;
    }

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        pos.push_back(P(x, y));
    }

    for (int d = 1; d <= D; d++) {
        Gk[d] = G;
    }
}

/// @brief 出力処理
/// @param  
void Output(void) {

    for (int i = 0; i < M; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

/// @brief 最短距離の計算 (隣接行列形式)
/// @param s 
priority_queue<P, vector<P>, greater<P>> que;
void Dijkstra(const Graph &G1 ,int s, vector<ll> &dis) {
    dis[s] = 0;

    que.push(make_pair(0, s));

    while(!que.empty()) {
        ll w = que.top().first;
        int v = que.top().second;
        que.pop();

        if (w > dis[v]) continue;

        for (auto e : G1[v]) {
            if (dis[e.to] > dis[v] + e.w) {
                dis[e.to] = dis[v] + e.w;
                que.push(make_pair(dis[e.to], e.to));
            }
        }
    }
}

/// @brief ランダムな2点を指定してfkを計算して返す。
/// @param  
/// @return 
double GetFk(const Graph &GG) {
    int v1, v2;
    v1 = rand() % N;

    disbuf.assign(1100, infl);
    dist.assign(1100,infl);

    Dijkstra(G, v1, dist);
    Dijkstra(GG, v1, disbuf);
    
    ll sum = 0;
    for (int v2 = 0; v2 < N; v2++) {
        if (v1 == v2) continue;
        ll d = disbuf[v2];
        if (d >= infl/2) d = 1e9;

        sum += (d - dist[v2]);
    }

    return (double)sum / (double)N / (double)(N-1);
}

double GetScore(void) {
    double sc = 0;
    for (int d = 0; d < D; d++) {
        double tmp = 0;
        tmp += GetFk(Gk[d]);
        sc += tmp;
    }
    return sc / (double)D * (double)10000;
}

/// @brief vecで指定したすべての辺を通行可能/不可にする
/// @param vec 
void SwapEdgeEnableDisable(vector<pair<int,int>> &vec) {
    /* 辺の通行禁止、可能を入れ替える */
    for (int i = 0; i < (int)vec.size(); i++) {
        int e1 = vec[i].first;
        int day1 = ans[e1];
        int t1 = mp[e1].first;
        int t2 = mp[e1].second;

        int e2 = vec[i].second;
        int day2 = ans[e2];
        int s1 = mp[e2].first;
        int s2 = mp[e2].second;

        int idx1 = mpidx[make_pair(t1, t2)];
        int idx2 = mpidx[make_pair(t2, t1)];
        int idx3 = mpidx[make_pair(s1, s2)];
        int idx4 = mpidx[make_pair(s2, s1)];

        Gk[day1][t1][idx1].w = G[t1][idx1].w;
        Gk[day1][t2][idx2].w = G[t2][idx2].w;
        Gk[day2][t1][idx1].w = infl;
        Gk[day2][t2][idx2].w = infl;

        Gk[day2][s1][idx3].w = G[s1][idx3].w;
        Gk[day2][s2][idx4].w = G[s2][idx4].w;
        Gk[day1][s1][idx3].w = infl;
        Gk[day1][s2][idx4].w = infl;

        if (e1 < M && e2 < M) swap(ans[e1], ans[e2]);
        else if (e1 >= M) {
            /* e1：-1, e2：+1 */
            ans[e1] = ans[e2];
        } else if (e2 >= M) {
            /* e1：+1, e1：-1 */
            ans[e2] = ans[e1];
        }
    }
}

/// @brief 
/// @param  
void Construction2(void) {

    /* 2頂点を選択して工事する日程をswapする */
    vector<pair<int,int>> vec;
    for (int i = 0; i < N/3; i++) {
        int e1 = rand() % M;
        int e2;
        while(1) {
            e2 = rand() % M;
            if (e1 != e2 && ans[e1] != ans[e2] && ((e1 < M) || (e2 < M))) break;
        }
        int day1 = ans[e1];
        int day2 = ans[e2];

        if (e1 >= M && (anssum[day2]+1) > K) continue;
        else if (e2 >= M && (anssum[day1]+1) > K) continue;
        
        vec.push_back(P(e1, e2));
    }
    SwapEdgeEnableDisable(vec);

    /* スコア計算 */
    double score_after = GetScore();

    /* スコアが改善されなかった場合は戻す */
    if (score < score_after) {
        vector<pair<int,int>> vec2;
        for (int i = vec.size()-1; i >= 0; i--) {
            int e1 = vec[i].first;
            int e2 = vec[i].second;
            vec2.push_back(P(e2, e1));
        }
        SwapEdgeEnableDisable(vec2);
    } else {
        /* スコア更新 */
        score = score_after;
        scores.push_back(score);
    }
}

/// @brief 1日当たり(m+(d-1))/d個の辺を工事する
/// @param  
void Construction1(void) {
    ll num = min((M + D - 1 ) / D, K);
    int yet = M;
    int cur = 0;
    for (int d = 1; d <= D; d++) {
        if (yet <= num) {
            num = yet;
            yet = 0;
        }
        for (int i = 0; i < num; i++) {
            ans[cur] = d;

            int v1 = mp[cur].first;
            int v2 = mp[cur].second;
            int idx1 = mpidx[make_pair(v1, v2)];
            int idx2 = mpidx[make_pair(v2, v1)];

//            cout << "v1 = " << v1 << "  v2 = " << v2 << "  G[d][v1][idx1] = " << Gk[d][v1][idx1].to << "  cur = " << cur << endl;

            Gk[d][v1][idx1].w = infl;
            Gk[d][v2][idx2].w = infl;
            
            anssum[d]++;
            cur++;
        }
        yet -= num;

        if (yet <= 0) break;
    }

    score = GetScore();
    scores.push_back(score);
}

int main()
{
    Input();

    clock_t start = clock(), end;
    clock_t bef = 0, af = 0, diffclock = 0;

    /* 初期解設定 */
    Construction1();

    /* 工事 */
    for (int i = 0; i < Count; i++) {
        Construction2();

        clock_t end = clock();
//        if (end - start + diffclock > 5700) break;
    }

    Output();

    end = clock();

#if DEBUG
    cout << "time:  " << end - start << endl;
    for (int i = 0; i < (int)scores.size(); i++) {
        cout << scores[i] << " ";
    }
    cout << endl;
#endif

    return 0;
}
