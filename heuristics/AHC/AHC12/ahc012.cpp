#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/* const */
#define ASIZE   (10)
#define KMAX    (100)
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

ll calc_score(vector<pair<int,int>> pp, vector<pair<int,int>> qq, vector<int> d, int kk) {
    long double slope1, slope2;
    for (int ii = 0; ii < kk-1; ++ii) {
        slope1 = (long double)(pp[ii].second - qq[ii].second) / (long double)(pp[ii].first - qq[ii].first);
        slope2 = (long double)(pp[ii+1].second - qq[ii+1].second) / (long double)(pp[ii+1].first - qq[ii+1].first);

        for (int jj = 0; jj < N; ++jj) {
            if (slope1 * pa[jj].first < pa[jj].second && (slope2 * pa[jj].first > pa[jj].second))  {
                d[ii]++;
            } else if (slope1 * pa[jj].first > pa[jj].second && (slope2 * pa[jj].first < pa[jj].second)) {
                d[ii+KMAX]++;
            }
        }
    }

    vector<int> dd(11, 0);
    for (int i = 0; i < d.size(); ++i) {
        if (d[i] >= 1 && d[i] <= 10) {
            dd[d[i]]++;
        }
    }

    long double ret = 0, asum = 0;
    for (int i = 1; i <= 10; ++i) {
        ret += min(a[i], dd[i]);
        asum += a[i-1];
    }

    ret = ((long double)ret * 1000000 / asum);
    
    return ret;
}

void test(void) {

    k++;
    p.push_back(make_pair(radius, 0));
    q.push_back(make_pair(-radius, 0));

    for (int i = 1; i < 100; ++i) {
        int px = rand() % 10000;
        int py = rand() % 10000;

        int t1 = rand()%2;
        int t2 = rand()%2;
        
        if (t1 == 1) {
            px = -px;
        } else if (t2 == 1) {
            py = -py;
        }

        t1 = rand() % 20;
        
        if (t1 == 1) continue;

        p.push_back(make_pair(px, py));

        t1 = rand()%2;
        t2 = rand()%2;
        
        int qx = rand() % 10000;
        int qy = rand() % 10000;

        if (t1 == 1) {
            qx = -qx;
        } else if (t2 == 1) {
            qy = -qy;
        }

        q.push_back(make_pair(qx, qy));
        k++;
    }

}

int main()
{
    input();
    test();
    output();

    return 0;
}
