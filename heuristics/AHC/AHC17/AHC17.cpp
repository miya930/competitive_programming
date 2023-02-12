//24,276,736,518
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
int loopNum = 2000;
int loopCnt = 0;
ll Temp = 200000;
ll loop = 20;
int cnt = 0;

int vv1;

vector<vector<int>> scores(loop+10);

/// @brief 1：e1 -> e2の日に移す、0：swap, -1：e2 -> e1の日に移す
///        Kを上回る場合はswapにする
vector<int> mo(1050);
double moThreshL = 0.0, moThreshU = 1;

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

    Dijkstra(GG, vv1, disbuf);
    
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

        /* 移す場合 */
        /* 1：e1 -> e2の日に移す、0：swap, -1：e2 -> e1の日に移す */
        bool ng = false;
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
        }

        /* swapする場合 */
        if (mo[i] == 0 || ng) {
            swap(ans[e1], ans[e2]);
        }
    }
}

/// @brief 
/// @param  
void Yamanobori(void) {

    /* 2頂点を選択して工事する日程をswapする */
    vector<pair<int,int>> vec;
    for (int i = 0; i < N/50; i++) {
        int e1 = rand() % M;
        int e2;
        while(1) {
            e2 = rand() % M;
            if (e1 != e2 && ans[e1] != ans[e2] && ((e1 < M) || (e2 < M))) break;
        }
        
        vec.push_back(P(e1, e2));
    }
    SwapEdgeEnableDisable(vec);

    /* スコア計算 */
    double newScore = GetScore();

    /* スコアが改善されなかった場合は戻す */
    if (currentScore < newScore) {
        vector<pair<int,int>> vec2;
        for (int i = vec.size()-1; i >= 0; i--) {
            int e1 = vec[i].first;
            int e2 = vec[i].second;
            vec2.push_back(P(e2, e1));
        }
        SwapEdgeEnableDisable(vec2);
    } else {
        /* スコア更新 */
        currentScore = newScore;
        scores[cnt].push_back(currentScore);
    }
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
vector<double> temperature;
vector<double> prob;
vector<double> scoreDiff;

void Yakinamashi(void) {
    /* 2頂点を選択して工事する日程をswapする */
    vector<pair<int,int>> vec;
    for (int i = 0; i < N/4; i++) {
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

    SwapEdgeEnableDisable(vec);

    /* スコア計算 */
    double newScore = GetScore();

    /* 採用確率の計算 */
    double T = (double)Temp - (double)Temp * (double)loopCnt / (double)loopNum;
    double probability = exp(min(0.0, (newScore - currentScore) / T));

//    probability = exp(min(0.0, (double)(-1000) / T));

    temperature.push_back(T);
    prob.push_back(probability);
    scoreDiff.push_back(newScore - currentScore);

    /* スコアが改善されなかった場合は戻す */
    if (Randouble() < probability) {
        vector<pair<int,int>> vec2;
        for (int i = vec.size()-1; i >= 0; i--) {
            int e1 = vec[i].first;
            int e2 = vec[i].second;
            vec2.push_back(P(e2, e1));
        }
        for (int i = 0 ; i < (int)mo.size(); i++) {
            mo[i] = -1*mo[i];
        }
        SwapEdgeEnableDisable(vec2);
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

int main()
{
    Input();

    clock_t start = clock(), end;
    clock_t bef = 0, af = 0, diffclock = 0;

    cnt = 10;
    vv1 = rand() % N;
    Dijkstra(G, vv1, dist);

    /* 初期解設定 */    
    AnsInitialize();

    for (loopCnt = 0; loopCnt < loopNum; loopCnt++) {
        Yakinamashi();
    }    

    Output();

    end = clock();

#if DEBUG
    cout << "time:  " << end - start << endl;
//    cout << endl;    
/*    cout << "--probability--" << endl;
    for (int i = 0; i < (int)prob.size(); i++) {
        cout << prob[i] << " ";
    }
    cout << endl;
    cout << "--diff--" << endl;
    for (int i = 0; i < (int)scoreDiff.size(); i++) {
        cout << scoreDiff[i] << " ";
    }
    cout << endl;*/    

#endif

    return 0;
}
