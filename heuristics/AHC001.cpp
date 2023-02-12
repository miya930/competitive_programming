#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct result {
    vector<int> a, b, c, d;
};

struct edge {
    int x;
    int y;
    int r;
};

int N;
vector<edge> e;

void input(istream& is, result& res) {
    is >> N;

    e.resize(N);
    res.a.resize(N);
    res.b.resize(N);
    res.c.resize(N);
    res.d.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> e[i].x >> e[i].y >> e[i].r;
    }
}

void solve(result& res) {
    
    /* 初期解 */
    for (int i = 0; i < N; i++) {
        res.a[i] = e[i].x;
        res.b[i] = e[i].y;
        res.c[i] = e[i].x + 1;
        res.d[i] = e[i].y + 1;
    }



} 

/// @brief 指定された形式で出力
/// @param os 
/// @param res 
void output(ostream& os, const result& res) {
    for (size_t i = 0; i < res.a.size(); i++) {
        os << res.a[i] << " " << res.b[i] << " " << res.c[i] << " " << res.d[i] << endl;
    }
}


#define DEBUG   (0)

int main()
{
    result res;

    input(cin, res);
    solve(res);

#if DEBUG
    ofstream ofs("log.csv");
    output(ofs, res);
#else
    output(cout, res);
#endif

    return 0;
}
