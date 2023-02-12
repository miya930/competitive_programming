// 21,437,185,465
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

vector<int> ans(3100);
int N, M, D, K;
double currentScore;
/// @brief ループ回数
int loopNum = 500;
int loopCnt = 0;
ll Temp = 1000;
ll loop = 20;
int cnt = 0;
int vv1;

vector<vector<int>> scores(loop+10);

/// @brief 1：e1 -> e2の日に移す、0：swap, -1：e2 -> e1の日に移す
///        Kを上回る場合はswapにする
vector<int> mo(1050);
vector<P> edgeLen;
double moThreshL = 0.0, moThreshU = 1;
vector<vector<int>> degree(40, vector<int>(3050, 0));
vector<pair<int,int>> degreeInit(3050);

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
        
        edgeLen.push_back(P(w, i));

        /* 頂点の次数を計算する */
        for (int d = 0; d < 40; d++) {
            degree[d][u]++;
            degree[d][v]++;
        }
    }

    for (int i = 0; i < M; i++) {
        degreeInit[i].first = degree[0][i];
        degreeInit[i].second = i;
    }
    sort(degreeInit.rbegin(), degreeInit.rend());

    sort(edgeLen.begin(), edgeLen.end());

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

    disbuf.assign(1100, infl);
    Dijkstra(GG, vv1, disbuf);
    
    ll sum = 0;
    for (int v2 = 0; v2 < N; v2++) {
        if (vv1 == v2) continue;
        ll d = disbuf[v2];
        if (d >= infl) d = 1e9;

        sum += (d - dist[v2]);
    }

    return (double)sum / (double)N / (double)(N-1);
}

double GetScore(void) {
    double sc = 0;
    for (int d = 1; d <= D; d++) {
        double tmp = 0;
        tmp += GetFk(Gk[d]);
        sc += tmp;
    }
    return sc / (double)D * (double)10000;
}


/// @brief 辺の通行可能不能を入れ替える
/// @param vec 
void SwapEdgeEnableDisable(int e1, int v11, int v12, int day1, int e2, int v21, int v22, int day2) {
    /* 辺の通行禁止、可能を入れ替える */
    /* グラフの更新をする */
    int v12idx = mpidx[make_pair(v11, v12)];
    int v11idx = mpidx[make_pair(v12, v11)];

    int v22idx = mpidx[make_pair(v21, v22)];
    int v21idx = mpidx[make_pair(v22, v21)];   

    Gk[day1][v11][v12idx].w = G[v11][v12idx].w;
    Gk[day1][v12][v11idx].w = G[v12][v12idx].w;
    Gk[day2][v11][v12idx].w = infl;
    Gk[day2][v12][v11idx].w = infl;

    Gk[day2][v21][v22idx].w = G[v21][v22idx].w;
    Gk[day2][v22][v21idx].w = G[v22][v21idx].w;
    Gk[day1][v21][v22idx].w = infl;
    Gk[day1][v22][v21idx].w = infl;   

    swap(ans[e1], ans[e2]);

    /* 移す場合 */
    /* 1：e1 -> e2の日に移す、0：swap, -1：e2 -> e1の日に移す */
/*    bool ng = false;
    if (mo[i] == 1) {
        if (anssum[day2]+1 <= K) {
            anssum[day2]++;
            anssum[day1]--;
            ans[e1] = day2;
        } else {
            ng = true;
        }
    } else if (mo[i] == -1) {
        if (anssum[day1]+1 <= K) {
            anssum[day1]++;
            anssum[day2]--;
            ans[e2] = day1;
        } else {
            ng = true;
        }
    }*/

    /* swapする場合 */
/*    if (mo[i] == 0 || ng) {
        swap(ans[e1], ans[e2]);
    }*/
    
}

/// @brief 0以上1以下のランダムな実数を返す関数
///        残り回数に応じて採用確立を調整する。
/// @param  
/// @return 
double Randouble(void) {
    return 1.0 * rand() / RAND_MAX;
}

/// @brief 焼きなまし法で工事計画を立てる
/// @param
vector<double> prob;
vector<double> scoreDiff;

// degreeの更新を行う.
void ChangeDegree(int v11, int v12, int day1, int v21, int v22, int day2) {
    degree[day1][v21]--;
    degree[day1][v22]--;
    degree[day2][v21]++;
    degree[day2][v22]++;

    degree[day2][v11]--;
    degree[day2][v12]--;
    degree[day1][v11]++;
    degree[day1][v12]++;
}

void Yakinamashi(void) {

    vector<pair<int,int>> vec;
    int cnt = 0;
    /* 2頂点を選択して工事する日程をswapする */
    for (int i = 0; i < 1; i++) {
        int e1 = rand() % M;
        int e2;
        while(1) {
            e2 = rand() % M;
            if (e1 == e2 || ans[e1] == ans[e2]) continue;

            /* 両端の頂点の一方でも次数が0になるなら更新しない */
            // 1個目の頂点
            int v11 = mp[e1].first;
            int v12 = mp[e1].second;
            int day1 = ans[e1];

            // 2個目の頂点
            int v21 = mp[e2].first;
            int v22 = mp[e2].second;
            int day2 = ans[e2];

            ChangeDegree(v11, v12, day1, v21, v22, day2);

            /* 次数が0になったら元に戻す */
            if (degree[day1][v21] <= 0 || degree[day1][v22] <= 0 || degree[day2][v11] <= 0 || degree[day2][v12] <= 0) {
                ChangeDegree(v21, v22, day2, v11, v12, day1);
                continue;
            }

            SwapEdgeEnableDisable(e1, v11, v12, day1, e2, v21, v22, day2);
            break;
        }        
        vec.push_back(P(e1, e2));
    }

    for (int i = 0; i < (int)vec.size(); i++) {
        double p = Randouble();

        if (p < moThreshL) {
            mo[i] = 1;
        } else if ( p > moThreshU) {
            mo[i] = -1;
        } else {
            mo[i] = 0;
        }
    }

    /* スコア計算 */
    double newScore = GetScore();

    /* 採用確率の計算 */
    double T = (double)Temp - (double)Temp * (double)loopCnt / (double)loopNum;
    double probability = exp(min(0.0, (newScore - currentScore) / T));

    prob.push_back(probability);
    scoreDiff.push_back(newScore - currentScore);

    /* スコアが改善されなかった場合は戻す(一定の確率で採用する) */
    if (Randouble() < probability) {
        for (int i = vec.size()-1; i >= 0; i--) {
            int e1 = vec[i].first;
            int e2 = vec[i].second;

            /* 両端の頂点の一方でも次数が0になるなら更新しない */
            // 1個目の頂点
            int v11 = mp[e1].first;
            int v12 = mp[e1].second;
            int day1 = ans[e1];

            // 2個目の頂点
            int v21 = mp[e2].first;
            int v22 = mp[e2].second;
            int day2 = ans[e2];

            SwapEdgeEnableDisable(e2, v21, v22, day2, e1, v11, v12, day1);
        }
/*        for (int i = 0 ; i < (int)mo.size(); i++) {
            mo[i] = -1*mo[i];
        }*/
    } else {
        /* スコア更新 */
        currentScore = newScore;
        scores[cnt].push_back(currentScore);
    }    
}

/// @brief 1日当たり(m+(d-1))/d個の辺を工事する
/// @param
void AnsInitialize(void) {
    /* Gk初期化 */
    for (int d = 1; d <= D; d++) {
        Gk[d] = G;
    }

    ll num = min((M + D - 1 + cnt) / D, K);
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

    currentScore = GetScore();
    scores[cnt].push_back(currentScore);
}

/// @brief 頂点とつながるすべての辺が工事中にならないように初期会を選択する
/// @param
vector<bool> selected;
void AnsInitializeMod(void) {
    /* Gk初期化 */
    for (int d = 1; d <= D; d++) {
        Gk[d] = G;
    }
    selected.assign(3010, false);

    ll num = min((M + D - 1) / D, K);
    int yet = M;
    int thres = 2 * num;
    for (int d = 1; d <= D; d++) {

        /* day = dのときに工事する辺を選択する.
         * 頂点に接続される辺の数が0にならないように選ぶ */
        int cnt = 0;
        int selectEdge = 0;
        while(1) {
            cnt++;

  //          cout << "cnt = " << cnt << "  yet = " << yet << endl;
            if (selectEdge >= num || yet <= 0) break;
            
            int sel = cnt % M;
            if (selected[sel]) continue;

            /* 残りの次数を計算 */
            int tmp = degree[d][sel] - 1;
            if (tmp <= 0 && cnt < thres) continue;

            /* 工事する */
            selected[sel] = true;
            degree[d][sel]--;

            selectEdge++;
            yet--;

            int v1 = mp[sel].first;
            int v2 = mp[sel].second;

            int v2idx = mpidx[make_pair(v1, v2)];
            int v1idx = mpidx[make_pair(v2, v1)];

            Gk[d][v1][v2idx].w = infl;
            Gk[d][v2][v1idx].w = infl;

            ans[sel] = d;
            
            anssum[d]++;
        }
    }

    currentScore = GetScore();
    scores[cnt].push_back(currentScore);    
}

int main()
{
    Input();

    clock_t start = clock(), end;

    /* 工事前最短距離計算 */
    vv1 = degreeInit[0].first;
    Dijkstra(G, vv1, dist);

    /* 初期解設定 */    
    AnsInitializeMod();

//    cout << "--score-- " << endl;
    /* 焼きなまし */
    for (loopCnt = 0; loopCnt < loopNum; loopCnt++) {
//        cout << currentScore << " ";
        Yakinamashi();
    }
    cout << endl;

    Output();

    end = clock();

#if DEBUG
    cout << "time:  " << end - start << endl;
    cout << endl;    
    cout << "--probability--" << endl;
    for (int i = 0; i < (int)prob.size(); i++) {
        cout << prob[i] << " ";
    }
    cout << endl;
    cout << "--diff--" << endl;
    for (int i = 0; i < (int)scoreDiff.size(); i++) {
        cout << scoreDiff[i] << " ";
    }
    cout << endl;

#endif

    return 0;
}
