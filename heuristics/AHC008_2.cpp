#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxturn = 300;

bool fense[31][31];

#define debug   (0)
#if debug
#include <fstream>
ofstream ofs("test.csv");
#endif

int n, m;
struct Pet {
    int x;
    int y;
    int t;
};

struct Human {
    int x;
    int y;
};

vector<Pet> pet;
vector<Human> human;

void input(void) {
    /* pet */
    cin >> n;
    pet.resize(n);
    for (int i = 0; i < n; ++i) cin >> pet[i].x >> pet[i].y >> pet[i].t;
    
    /* human */
    cin >> m;
    human.resize(m);
    for (int i = 0; i < m; ++i) cin >> human[i].x >> human[i].y;

#if debug
    string seed;
    cin >> seed;
#endif
}

#if debug
void output(string ans, string pet) {
    cout << ans << pet << endl;
    ofs << ans << endl;
    ofs << pet << endl;
    cout << flush;
}

#else
void output(string str) {
    cout << str << endl;
    cout << flush;
}
#endif

#if debug
void check_pos(char mov, int pet_id) {
    
}


void update_pet_pos(char c, int pet_id) {

    switch(c) {
        case 'R':
            pet[pet_id].y++;
            break;
        case 'L':
            pet[pet_id].y--;
            break;
        case 'U':
            pet[pet_id].x--;
            break;
        case 'D':
            pet[pet_id].x++;
            break;
        default:
            break;
    }
}

#else
void update_pet_pos(void) {    

    vector<string> str(n);
    
    for (int i = 0; i < n; ++i) cin >> str[i];

    for (int i = 0; i < n; ++i) {
        int si = str[i].size();
        for (int j = 0; j < si; ++j) {
            switch(str[i][j]) {
                case 'R':
                    pet[i].y++;
                    break;
                case 'L':
                    pet[i].y--;
                    break;
                case 'U':
                    pet[i].x--;
                    break;
                case 'D':
                    pet[i].x++;
                    break;
            }
        }
    }
}
#endif

bool done_init = false;
bool done_last = false;
char lastmove = 'L';
vector<Human> init_pos = {{20, 1}};
vector<Human> last_pos = {{30, 10}};

char init_human_pos(int hum_id) {
    char ret;

    if (hum_id == 0) {
         if (human[hum_id].x < init_pos[hum_id].x) {
            ret = 'D';
            human[hum_id].x++;
         } else if (human[hum_id].x > init_pos[hum_id].x) {
            ret = 'U';
            human[hum_id].x--;
         } else if (human[hum_id].y < init_pos[hum_id].y) {
            ret = 'R';
            human[hum_id].y++;
         } else if (human[hum_id].y > init_pos[hum_id].y) {
            ret = 'L';
            human[hum_id].y--;
         }
         lastmove = ret;
    } else {
        ret = '.';
    }

    if (human[hum_id].x == init_pos[hum_id].x && human[hum_id].y == init_pos[hum_id].y) {
        done_init = true;
        lastmove = 'R';
    }

    return ret;
}

bool lastact = false;   // false：move, true：fence

/* 初期化後の動作 */
char move_human_pos(int hum_id) {
    char ret;

    if (hum_id == 0) {
         if (human[hum_id].y < last_pos[hum_id].y) {
             ret = 'R';
             human[hum_id].y++;
         } else if (human[hum_id].y > last_pos[hum_id].y) {
             ret = 'L';
             human[hum_id].y--;
         } else if (human[hum_id].x < last_pos[hum_id].x) {
             ret = 'D';
             human[hum_id].x++;
         } else if (human[hum_id].x > last_pos[hum_id].x) {
             ret = 'U';
             human[hum_id].x--;
         }
         lastmove = ret;
    } else {
        ret = '.';
        return ret;
    }

    lastact = false; 

    if (human[hum_id].x == last_pos[hum_id].x && human[hum_id].y == last_pos[hum_id].y) done_last = true;    

    return ret;
}

/* 柵 */
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int cnt = 0;

char make_fence(int hum_id) {
    char ret;
    int fenx = human[hum_id].x;
    int feny = human[hum_id].y;
    
    if (hum_id == 0) {
        if (lastmove == 'R') {
            ret = 'u';
            fenx--;
        } else if (lastmove == 'L') {
            ret = 'd';
            fenx++;
        } else if (lastmove == 'U') {
            ret = 'l';
            feny--;
        } else if (lastmove == 'D') {
            ret = 'r';
            feny++;
        }
    } else {
        ret = '.';
        return ret;
    }

    bool ok = true;

    /* 周囲にペットいないかチェック */
    for (int i = 0; i < 4; ++i) {
        int nx = fenx + dx[i];
        int ny = feny + dy[i];
        
        for (int j = 0; j < n; ++j) {
            if (nx == pet[j].x && ny == pet[i].y) ok = false;
        }
    }

    for (int i = 0; i < m; ++i) {
        if (fenx == human[i].x && feny == human[i].y) ok = false;
    }

    if (ok) lastact = true;
    else ret = '.';

    if (cnt == 0 && human[hum_id].x == init_pos[hum_id].x && human[hum_id].y == last_pos[hum_id].y) {
        cnt++;
        lastmove = 'D';
        lastact = false;
    }

    if (ret != '.') fense[fenx][feny] = true;

    return ret;
}

char make_pet_move(int pet_id) {
    char ret;

    int petmove = rand();
    petmove %= 4;

    int vx    = pet[pet_id].x;
    int vy    = pet[pet_id].y;
    
    bool cant = true;
    for (int i = 0; i < 4; ++i) {
        int nx = vx + dx[i];
        int ny = vy + dy[i];

        if (fense[nx][ny]) cant = false;
    }

    if (cant == true) return '.';

    switch(petmove) {
        case 0:
            if (pet[pet_id].x-1 < 1) ret = 'D';
            else ret = 'U';
            break;
        case 1:
            if (pet[pet_id].x+1 > 30) ret = 'U';
            else ret = 'D';
            break;
        case 2:
            if (pet[pet_id].y-1 < 1) ret = 'R';
            else ret = 'L';
            break;
        case 3:
            if (pet[pet_id].y+1 > 30) ret = 'L';
            else ret = 'R';
            break;
    }

    return ret;
}

int main()
{
    input();

    for (int turn = 0; turn < maxturn; ++turn) {
        string ans = "";

        for (int hum_id = 0; hum_id < m; hum_id++) {

            if (!done_init) {
                ans = ans + init_human_pos(hum_id);
            } else {
                if (done_last) {
                    ans = ans + '.';
                    continue;
                }

                if (!lastact) {
                    ans = ans + make_fence(hum_id);
                } else {
                    ans = ans + move_human_pos(hum_id);
                }
            }

        }

#if debug
        string s = "";
        for (int i = 0; i < n; ++i) {
            string tmps = "";
            char tmpc;

            int tmp = 0;
            if (pet[i].t == 1) tmp = 1;
            else if (pet[i].t == 2 || pet[i].t == 4 || pet[i].t == 5) tmp = 2;
            else if (pet[i].t == 3) tmp = 3;

            for (int j = 0; j < tmp; ++j) {
                tmpc = make_pet_move(i);
                update_pet_pos(tmpc, i);
                tmps += tmpc;
            }
            s += tmps;
            s += ' ';
        }

        output(ans, s);
#else

        output(ans);
        update_pet_pos();

#endif
    }

    return 0;
}
