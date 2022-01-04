#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int inf = 1001001001;

const int CENTER = 400;
const int PICKUP = 50;
const int MAXCNT = 1000;

vector<int> rest_x, rest_y, dest_x, dest_y;
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
    result_x.push_back(CENTER);
    result_x.push_back(CENTER);
    result_y.push_back(CENTER);
    result_y.push_back(CENTER);

    vector<int> candidates(MAXCNT);
    iota(candidates.begin(), candidates.end(), 0);

    for (int i = 0; i < PICKUP; ++i) {
        int min_dist = inf;
        int min_idx  = 0, min_idx_1 = 0, min_idx_2 = 0;

        for (int j = 0; j < (int)candidates.size(); ++j) {
            int v = candidates[j];
            int x0 = rest_x[v];
            int y0 = rest_y[v];
            int x1 = dest_x[v];
            int y1 = dest_y[v];

            for (int s = 1; s < (int)result_x.size(); ++s) {
                int old_dist_rest = dist(result_x[s-1], result_y[s-1], result_x[s], result_y[s]);
                int d00           = dist(result_x[s-1], result_y[s-1], x0, y0);
                int d01           = dist(x0, y0, result_x[s], result_y[s]);

                int new_dist_rest  = d00 + d01;
                int dist_diff_rest = new_dist_rest - old_dist_rest;

                result_x.insert(result_x.begin()+s, x0);
                result_y.insert(result_y.begin()+s, y0);

                for (int t = s+1; t < (int)result_x.size(); ++t) {
                    int old_dist_dest  = dist(result_x[t-1], result_y[t-1], result_x[t], result_y[t]);
                    int d10            = dist(result_x[t-1], result_y[t-1], x1, y1);
                    int d11            = dist(x1, y1, result_x[t], result_y[t]);
                    
                    int new_dist_dest  = d10 + d11; 
                    int dist_diff_dest = new_dist_dest - old_dist_dest;

                    int dist_diff      = dist_diff_dest + dist_diff_rest;

                    if (dist_diff < min_dist) {
                        min_dist = dist_diff;
                        min_idx   = j;
                        min_idx_1 = s;
                        min_idx_2 = t;
                    }
                }

                result_x.erase(result_x.begin()+s);
                result_y.erase(result_y.begin()+s);

            }
        }

        int s = min_idx;
        int t = min_idx_1;
        int u = min_idx_2;
        int v = candidates[s];

        selected.push_back(v);
        candidates.erase(candidates.begin()+s);

        result_x.insert(result_x.begin()+t, rest_x[v]);
        result_y.insert(result_y.begin()+t, rest_y[v]);
        result_x.insert(result_x.begin()+u, dest_x[v]);
        result_y.insert(result_y.begin()+u, dest_y[v]);

    }
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

    solve();
    output();

    return 0;
}
