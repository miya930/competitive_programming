// 焼きなまし法

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> x, y, ans;
vector<bool> visited;
int n;
const double inf = 100100.0;

int RandInt(int a, int b) {
    return a + rand() % (b - a + 1);
}

double Randdouble() {
    return 1.0 * rand() / RAND_MAX;
}

double GetDistance(int p, int q) {
    return sqrt((x[p]-x[q])*(x[p]-x[q])+(y[p]-y[q])*(y[p]-y[q]));
}

double GetScore() {
    double sum = 0;
    for (int i = 0; i < n; ++i) sum += GetDistance(ans[i], ans[i+1]);
    return sum;
}

int main()
{
    
    cin >> n;
    x.resize(n); y.resize(n);
    visited.assign(n, false);
    ans.assign(n+1, 0);

    for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];

    ans[0] = 0; ans[n] = 0;

    for (int i = 1; i < n; ++i) ans[i] = i;

    double curScore = GetScore();
    for (int t = 0; t < 200000; t++){
        int l = RandInt(1, n-1);
        int r = RandInt(1, n-1);
        if (l > r) swap(l, r);

        reverse(ans.begin() + l, ans.begin() + r + 1);
        double newScore = GetScore();

        double T = 30.00 - 28.00 * t / 200000.0;
        double Probability = exp(min(0.0, (curScore - newScore) / T));
        if (Randdouble() < Probability) curScore = newScore;
        else reverse(ans.begin() + l, ans.begin() + r + 1);

    }

    for (int i = 0; i <= n; ++i) cout << ans[i] << endl;
    cout << "Score = " << curScore << endl;
    return 0;
}
