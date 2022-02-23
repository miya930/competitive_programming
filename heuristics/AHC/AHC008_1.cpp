/* その場から動かないパターン */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxcnt = 300;

struct animal {
    int x;
    int y;
    int t;
};

struct human {
    int x;
    int y;
};

int n, m;
vector<animal> ani;
vector<human>  hum;
vector<string> ans(maxcnt);

/* prototype */
void output(void);

void input(void) {
    cin >> n;
    ani.resize(n);

    for (int i = 0; i < n; ++i) {
        int x, y, t;
        cin >> x >> y >> t;
        ani[i].x = x;
        ani[i].y = y;
        ani[i].t = t;
    }

    cin >> m;
    hum.resize(m);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        hum[i].x = x;
        hum[i].y = y;
    }
    /*string seed;
    cin >> seed;*/
}

void update_ani_pos(void) {    

    vector<string> str(n);
    for (int i = 0; i < n; ++i) cin >> str[i];

    for (int i = 0; i < n; ++i) {
        int si = str[i].size();
        for (int j = 0; j < si; ++j) {
            switch(str[i][j]) {
                case 'R':
                    ani[i].y++;
                    break;
                case 'L':
                    ani[i].y--;
                    break;
                case 'U':
                    ani[i].x--;
                    break;
                case 'D':
                    ani[i].x++;
                    break;
            }
        }
    }
}

void output(void) {
    string to = "";
    for (int i = 0; i < m; ++i) to += '.';
    cout << to << endl;
    cout << flush;
}

int main()
{

    input();

    for (int i = 0; i < maxcnt; ++i) {
        /* 人の行動 */
        output();

        update_ani_pos();
    }

    return 0;
}
