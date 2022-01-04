#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int inf = 1001001001;

const int CENTER = 400;
const int PICKUP = 50;
const int MAXCNT = 1000;

vector<int> rest_x, rest_y, dest_x, dest_y;
vector<int> candidates;
vector<int> result_x, result_y, selected;

// s : start, g : goal
int dist(int sx, int sy, int gx, int gy) {
    return abs(sx-gx)+abs(sy-gy); 
}

// nearest neighbor algorithm
void solve(void) {

    // initialize
    int cur_x = CENTER;
    int cur_y = CENTER;
    iota(candidates.begin(), candidates.end(), 0);
    result_x.push_back(CENTER);
    result_y.push_back(CENTER);

    // restaurant
    for (int i = 0; i < PICKUP; ++i) {
        int min_dist = inf;
        int min_idx  = inf;

        for (int j = 0; j < (int)candidates.size(); ++j) {
            int v = candidates[j];
            int d = dist(cur_x, cur_y, rest_x[v], rest_y[v]);

            if (d < min_dist) {
                min_dist = d;
                min_idx  = j;
            }
        }

        int v = candidates[min_idx];
        selected.push_back(v);
        result_x.push_back(rest_x[v]);
        result_y.push_back(rest_y[v]);
        cur_x = rest_x[v];
        cur_y = rest_y[v];
        candidates.erase(candidates.begin()+min_idx);
    }

    // copy dest lists
    candidates = selected;

    // destination
    for (int i = 0; i < PICKUP; ++i) {
        int min_dist = inf;
        int min_idx  = inf;

        for (int j = 0; j < (int)candidates.size(); ++j) {
            int v = candidates[j];
            int d = dist(cur_x, cur_y, dest_x[v], dest_y[v]); 
            if (d < min_dist) {
                min_dist = d;
                min_idx  = j;
            }
        }

        int v = candidates[min_idx];
        result_x.push_back(dest_x[v]);
        result_y.push_back(dest_y[v]);
        cur_x = dest_x[v];
        cur_y = dest_y[v];
        candidates.erase(candidates.begin() + min_idx);
    }

    result_x.push_back(CENTER);
    result_y.push_back(CENTER);

}

void output(void) {
    int sz = selected.size();
    cout << sz << " ";
    for (int i = 0; i < sz; ++i) {
        cout << selected[i]+1 << " ";
    }
    cout << endl;

    cout << result_x.size() << " ";
    for (int i = 0; i < (int)result_x.size(); ++i) {
        cout << result_x[i] << " " << result_y[i] << " ";
    }
}

int main()
{
    // input
    for (int i = 0; i < MAXCNT; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        rest_x.push_back(a);
        rest_y.push_back(b);
        dest_x.push_back(c);
        dest_y.push_back(d);

    }

    candidates.resize(MAXCNT);
    solve();
    output();

    return 0;
}
