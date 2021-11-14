#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
const int inf = 1001001001;

struct edge {
    int idx;
    int vx;
    int vy;
    int nx;
    int ny;
    int vdist;
    int ndist;
    int sumdist;
};

struct Root {
    P pos;
    int idx;
    int flag;  // flag = 0 : start, flag = 1 : goal

};

vector<Root> root;
vector<int> root_idx;

void output(const int m, vector<int> root_idx, int n) {
    cout << m << " ";
    for (int i = 0; i < (int)root_idx.size(); ++i) {
        cout << root_idx[i] << " ";
    }
    cout << endl;

    cout << n << " ";
    for (int i = 0; i < (int)root.size(); ++i) {
        cout << root[i].pos.first << " " << root[i].pos.second << " ";
    }
    cout << endl;
}

int main()
{
    int n = 1000;
    vector<edge> e(n);

    // input
    for (int i = 0; i < n; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        e[i].idx = i+1;
        e[i].vx = a;
        e[i].vy = b;
        e[i].nx = c;
        e[i].ny = d;

        e[i].vdist = abs(400-a) + abs(400-b);
        e[i].ndist = abs(400-c) + abs(400-d);
        e[i].sumdist = e[i].vdist + e[i].ndist;
    }

    // for edge
    auto cmp = [](edge s, edge t) -> bool {
        return s.sumdist < t.sumdist;
    };
    sort(e.begin(), e.end(), cmp);

    // root
    int m = 50;
    for (int i = 0; i < m; ++i) {
        root_idx.push_back(e[i].idx);
        
        int sx = e[i].vx;
        int sy = e[i].vy;

        Root s;
        s.pos = P(sx,sy); s.flag = 0; s.idx = e[i].idx;
        root.push_back(s);
    }

    for (int i = 0; i < m; ++i) {
        
        int tx = e[i].nx;
        int ty = e[i].ny;

        Root t;
        t.pos = P(tx,ty); t.flag = 1; t.idx = e[i].idx;
        root.push_back(t);
    }

    vector<bool> seen(m, false);

    int cnt = 0;
    int cntmax = 10000;

    while (cnt < cntmax) {
        seen.assign(m, false);

        for (int i = 0; i < m-1; ++i) {
            pair<int, int> dist = P(inf, -1);
            bool change = false;

            for (int j = 0; j <= i; ++j) {
                if (root[j].flag = 0) seen[j] = true;
            }
            
            for (int j = i+1; j < m; ++j) {
               if (root[j].flag == 0 || ((root[j].flag == 1) && (seen[root[j].idx] == true))) {
                   int temp = abs(root[i].pos.first - root[j].pos.first) + abs(root[i].pos.second - root[j].pos.second);
                   if (temp < dist.first) {
                       dist.first = temp;
                       dist.second = j;
                       change = true;
                   }
               }
            }

            if (change) {
                P tempP = root[i+1].pos;
                int tempf = root[i+1].flag;
                int tempidx = root[i+1].idx;

                int j = dist.second;
                root[i+1].pos = root[j].pos;
                root[i+1].flag = root[j].flag;
                root[i+1].idx = root[j].idx;

                root[j].pos = tempP;
                root[j].flag = tempf;
                root[j].idx = tempidx;
            }
        }
        
        cnt++;
    }
    
    // add start / goal
    Root start, goal;
    start.pos = P(400, 400); start.flag = 0; start.idx = -1;
    goal.pos = P(400, 400); goal.flag = 1; goal.idx = -1;
    root.insert(root.begin(), start);
    root.push_back(goal);

    output(m, root_idx, root.size());

    return 0;
}
