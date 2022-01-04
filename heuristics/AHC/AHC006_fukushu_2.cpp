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
    result_y.push_back(CENTER);

    vector<int> candidates_rest;
    vector<int> candidates_dest;

    for (int i = 0; i < MAXCNT; ++i) {
        int sd = dist(cur_x, cur_y, rest_x[i], rest_y[i]);
        int gd = dist(cur_x, cur_y, dest_x[i], dest_y[i]);
        if (sd <= 400 && gd <= 400) {
            candidates_rest.push_back(i);
        }
    }

    // restaurant
    for (int i = 0; i < PICKUP*2; ++i) {
        int min_dist = inf;
        int min_idx  = inf;
        bool is_restaurant = true;

        for (int j = 0; j < (int)candidates_rest.size(); ++j) {
            int v = candidates_rest[j];
            int d = dist(cur_x, cur_y, rest_x[v], rest_y[v]);

            if (d < min_dist) {
                min_dist = d;
                min_idx  = j;
                is_restaurant = true;
            }
        }

        for (int j = 0; j < (int)candidates_dest.size(); ++j) {
            int v = candidates_dest[j];
            int d = dist(cur_x, cur_y, dest_x[v], dest_y[v]);

            if (d < min_dist) {
                min_dist = d;
                min_idx  = j;
                is_restaurant = false;
            }
        }

        int x, y;

        if (is_restaurant) {

            int v = candidates_rest[min_idx];
            selected.push_back(v);
            x = rest_x[v];
            y = rest_y[v];
            candidates_dest.push_back(v);

            if (selected.size() >= 50) {
                candidates_rest.clear();
            } else {
                candidates_rest.erase(candidates_rest.begin() + min_idx);
            }

        } else {

            int v = candidates_dest[min_idx];
            x = dest_x[v];
            y = dest_y[v];
            candidates_dest.erase(candidates_dest.begin() + min_idx);

        }

        result_x.push_back(x);
        result_y.push_back(y);
        cur_x = x;
        cur_y = y;
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

    solve();
    output();

    return 0;
}
