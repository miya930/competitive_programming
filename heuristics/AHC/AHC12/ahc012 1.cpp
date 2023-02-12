#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/* const */
#define ASIZE   (10)
const long double pi = 3.1415926535;
const int center_x = 0;
const int center_y = 0;
const int radius = 10000;

/* input / output */
int N, K, k;
vector<int> a;
vector<pair<int,int>> pa;
vector<pair<int,int>> p, q;

void input(void) {
    cin >> N >> K;
    a.resize(ASIZE);
    pa.resize(N);
    for (int i = 0; i < 10; ++i) cin >> a[i];
    for (int i = 0; i < N; ++i)  cin >> pa[i].first >> pa[i].second;
}

void output(void) {
    cout << k << endl;
    for (int i = 0; i < k; ++i) {
        cout << p[i].first << " " << p[i].second << " " << q[i].first << " " << q[i].second << endl;
    }
}

void test(void) {

    // center
    p.push_back(make_pair(radius, 0));
    q.push_back(make_pair(-radius, 0));

    for (int i = 1; i < 100; ++i) {
        k++;
        int px = (long double)radius * cosl((long double)i * pi / (long double)180.0);
        int py = (long double)radius * sinl((long double)i * pi / (long double)180.0);
        p.push_back(make_pair(px, py));
        q.push_back(make_pair(0, 0));
    }
}

int main()
{
    input();
    test();
    output();

    return 0;
}
