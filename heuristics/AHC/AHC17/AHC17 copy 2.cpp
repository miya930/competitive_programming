/// 2/4  22,668,468,582 
#include <bits/stdc++.h>
#define DEBUG   (0)
#if DEBUG
#include <filesystem>
#include <fstream>
#include <string_view>
#endif
using namespace std;
using namespace chrono;
using ll = long long;
using P = pair<ll,int>;
const ll infl = 1LL << 60;

struct edge {
    int to;
    ll w;
};
using Graph = vector<vector<edge>>;

Graph G(1050);
vector<Graph> Gk(40, Graph(1050));
/// @brief 工事しない場合の最短距離
vector<vector<ll>> dist(1010, vector<ll>(1050, infl));
int maxvv1 = 1;
vector<int> vv1List(maxvv1);
/// @brief 工事する場合の最短距離. 
vector<vector<ll>> disbuf(1010, vector<ll>(1050, infl));
/// @brief 各頂点の座標
vector<pair<int,int>> pos;
vector<int> anssum(40, 0);
map<int,P> mp;
map<pair<int,int>, int> mpidx;

vector<int> ans(3100);
int N, M, D, K;
double currentScore;
/// @brief ループ回数
const double END_TIME = 5.8;
double measuredTime = 0.0;
int cnt = 0;
ll Temp = 10000;
int exec = 0;

vector<double> lensum(1050);
vector<pair<double, int>> lenave(1050);
vector<pair<double, int>> position(1050);

/// @brief 1：e1 -> e2の日に移す、0：swap, -1：e2 -> e1の日に移す
///        Kを上回る場合はswapにする
vector<int> mo(1050);
vector<P> edgeLen;
double moThreshL = 0.0, moThreshU = 1;
vector<vector<int>> degree(40, vector<int>(1050, 0));
vector<pair<int,int>> degreeInit;
bool flg = false;
int counter = 0;

void Input(istream& is) {

    is >> N >> M >> D >> K;
    
    for (int i = 0; i < M; i++) {
        int u, v;
        ll w;
        is >> u >> v >> w;
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

        lensum[u] += w;
        lensum[v] += w;
    }

    position.assign(N, make_pair(0, 0));
    for (int i = 0; i < N; i++) {
        int x, y;
        is >> x >> y;
        pos.push_back(P(x, y));
        position[i] = make_pair((x-500)*(x-500)+(y-500)*(y-500), i);
    }
    sort(position.rbegin(), position.rend());

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

/// @brief vv1Listに格納された頂点とそれ以外の頂点間の距離の和を計算し、 N(N-1)で割った値を返す
/// @param  
/// @return
double GetFk(const Graph &GG) {
    
    ll sum = 0;
    for (int i = 0; i < maxvv1; i++) {
        int vv1 = vv1List[i];
        disbuf[vv1].assign(N, infl);
        Dijkstra(GG, vv1, disbuf[vv1]);
        
        for (int v2 = 0; v2 < N; v2++) {
            if (vv1 == v2) continue;
            ll d = disbuf[vv1][v2];
            if (d >= infl) d = 1e9;

            sum += (d - dist[vv1][v2]);
//            if (d < dist[vv1][v2]) cout << d << "  " << dist[vv1][v2] << endl;
        }
    }
    return (double)sum / (double)N / (double)(N-1) / (double)maxvv1;
}

/// @brief スコアを計算する
/// @param  void
/// @return void
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
    Gk[day1][v12][v11idx].w = G[v12][v11idx].w;
    Gk[day2][v11][v12idx].w = infl;
    Gk[day2][v12][v11idx].w = infl;

    Gk[day2][v21][v22idx].w = G[v21][v22idx].w;
    Gk[day2][v22][v21idx].w = G[v22][v21idx].w;
    Gk[day1][v21][v22idx].w = infl;
    Gk[day1][v22][v21idx].w = infl;   

    swap(ans[e1], ans[e2]);
    
}

/// @brief 0以上1以下のランダムな実数を返す関数
///        残り回数に応じて採用確立を調整する。
/// @param  
/// @return 
double Randouble(void) {
    return 1.0 * rand() / RAND_MAX;
}

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

/// @brief 焼きなまし法で工事計画を立てる
/// @param
void Yakinamashi(void) {

    vector<pair<int,int>> vec;
    int cnt = 0;
    /* 2頂点を選択して工事する日程をswapする */
    for (int i = 0; i < 5; i++) {
        
        int e1 = rand() % M;
        int e2;
        while(1) {

            e2 = rand() % M;
            cnt++;
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
    double T = (double)Temp - (double)Temp * measuredTime / END_TIME;
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
    }
}


/// @brief 焼きなまし法で工事計画を立てる
/// @param
void Yakinamashi2(void) {

    vector<pair<int,int>> vec;
    int counter = 10;

    /* 2頂点を選択して工事する日程をswapする */
    for (int i = 0; i < counter; i++) {
        
        int e1 = rand() % M;
        int e2;
        while(1) {

            e2 = rand() % M;
            if (e1 == e2 || ans[e1] == ans[e2]) continue;

            // 1個目の頂点
            int v11 = mp[e1].first;
            int v12 = mp[e1].second;
            int day1 = ans[e1];

            // 2個目の頂点
            int v21 = mp[e2].first;
            int v22 = mp[e2].second;
            int day2 = ans[e2];

            SwapEdgeEnableDisable(e1, v11, v12, day1, e2, v21, v22, day2);
            break;
        }        
        vec.push_back(P(e1, e2));
    }

    /* スコア計算 */
    double newScore = GetScore();

    /* 採用確率の計算 */
    double T = (double)Temp - (double)Temp * measuredTime / END_TIME;
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

    } else {
        /* スコア更新 */
        currentScore = newScore;
    }
}

/// @brief 頂点とつながるすべての辺が工事中にならないように初期会を選択する
/// @param
vector<bool> selected(3010, false);
void AnsInitializeMod(void) {
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

            Gk[d][v1][idx1].w = infl;
            Gk[d][v2][idx2].w = infl;
            
            anssum[d]++;
            cur++;
        }
        yet -= num;

        if (yet <= 0) break;
    }

    currentScore = GetScore();

    Temp = currentScore / 10;
}

void resolve(void) {

    /* 工事前最短距離計算 */
    for (int i = 0; i < maxvv1; i++) {
        int vv1 = position[i].second;
        vv1List[i] = vv1;
        Dijkstra(G, vv1, dist[vv1]);
    }
 
    /* 初期解設定 */    
    AnsInitializeMod();

#if DEBUG
    cout << "--score-- " << endl;
#endif
    
    /* 焼きなまし */
    auto startClock = system_clock::now();
    do {
#if DEBUG        
        cout << currentScore << " ";
#endif        
        Yakinamashi2();

        measuredTime = (duration_cast<microseconds>(system_clock::now() - startClock).count() * 1e-6);
        exec++;

    } while (measuredTime < END_TIME);

#if DEBUG
    cout << "time = " << measuredTime << endl;
    cout << "cnt = " << exec << endl;

    cout << endl;
#endif
    Output();


#if DEBUG 
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
}

int main()
{
#if DEBUG
//    string base_path = "test_in/";
//    fstream ifs("test_in/0000.txt");

#else

#endif

    Input(cin);
    resolve();

    return 0;
}
