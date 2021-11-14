#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAP_SIZE = 10000;

struct advertise {
    int rowl;
    int coll;
    int rowh;
    int colh;

    int area;

    void calcarea(void) {
        area = (rowh - rowl) * (colh - coll);
    }
};

struct input {
    int x;
    int y;
    int area;
};

void output(const vector<advertise> ad) {
    int siz = ad.size();
    for (int i = 0; i < siz; ++i) {
        cout << ad[i].coll << " " << ad[i].rowl << " " << ad[i].colh << " " << ad[i].rowh << endl;
    }
}

void checkmax(advertise &ad) {
    if (ad.colh >= 10000) ad.colh--;
    if (ad.coll < 0) ad.coll--;
    if (ad.rowh >= 10000) ad.rowh--;
    if (ad.rowl < 0) ad.rowl--;
}

void plusarea(const vector<advertise> ad) {

}

int main()
{
    int n;
    cin >> n;

    vector<input> num(n);
    vector<advertise> ad(n);

    // input
    for (int i = 0; i < n; ++i) cin >> num[i].x >> num[i].y >> num[i].area;

    for (int i = 0; i < n; ++i) {
        ad[i].rowl = num[i].x;
        ad[i].coll = num[i].y;
        ad[i].rowh = num[i].x + 1;
        ad[i].colh = num[i].y + 1;

        ad[i].calcarea();
    }

    // output
    output(ad);

    return 0;
}
