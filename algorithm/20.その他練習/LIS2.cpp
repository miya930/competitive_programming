/*
 * LISをセグメント木を使用して解く
 * セグメント木の根のインデックスは1になっている。
 * だから 各頂点の子のインデックスは 2*i, 2*i+1になっている。 (根のインデックスが0の場合は 2*i+1, 2*i+2)
 * 
 * https://qiita.com/drken/items/68b8503ad4ffb469624c#3-lis-%E3%81%AE%E8%A7%A3%E6%B3%951-%E4%BA%8C%E5%88%86%E6%8E%A2%E7%B4%A2-ver
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

template<class Monoid> struct SegTree {
    using Func = function<Monoid(Monoid, Monoid)>;
    const Func F;
    const Monoid unity;
    int SIZE_R;
    vector<Monoid> dat;

    SegTree(int n, const Func f, const Monoid &unity) : F(f), unity(unity) { init(n); }
    void init(int n) {
        SIZE_R = 1;
        while (SIZE_R < n) SIZE_R *= 2;
        dat.assign(SIZE_R * 2, unity);
    }

    void set(int a, const Monoid& v) { dat[a + SIZE_R] = v; }
    void build() {
        for (int k = SIZE_R - 1; k > 0; --k)
            dat[k] = F(dat[2 * k], dat[2 * k + 1]);
    }

    void update(int a, const Monoid& v) {
        int k = a * SIZE_R;
        dat[k] = v;
        while (k >>= 1) dat[k] = F(dat[k * 2], dat[k * 2 + 1]);
    }

    Monoid get(int a, int b) {
        Monoid vleft = unity, vright = unity;
        for (int left = a + SIZE_R, right = b + SIZE_R; left < right; left >>= 1, right >>= 1) {
            if (left & 1) vleft = F(vleft, dat[left++]);
            if (right & 1) vright = F(dat[--right], vright); // [left, right)のため
        }
    }
    inline Monoid operator [] (int a) { return dat[a + SIZE_R]; }

};

int LIS(const vector<long long>& a) {
    int n = (int)a.size();
    vector<long long> aval;
    for (int i = 0; i < n; ++i) aval.push_back(a[i]);
    sort(aval.begin(), aval.end());
    aval.erase(unique(aval.begin(), aval.end()), aval.end()); // unique：重複内要素をコンテナの先頭に集め、戻り値は末尾を返す。eraseで余った後ろ側をすべて削除する

    SegTree<int> dp(n + 1, [](int a, int b) { return max(a, b); }, 0);

    int res = 0;
    for (int i = 0; i < n; ++i) {
        int h = lower_bound(aval.begin(), aval.end(), a[i]) - aval.begin();
        ++h;

        int A = dp.get(0, h);

        if (dp.get(h, h + 1) < A + 1) {
            dp.update(h, A + 1);
            res = max(res, A + 1);
        }
    }

    return res;
}

int main()
{
    int n; cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    cout << LIS(a) << endl;

    return 0;
}
