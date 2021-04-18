// バケット・ソートを利用する。
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    // バケット
    vector<int> Num(N,0);

    for (int i = 0; i < N; i++) {
        Num[A[i]-1]++;
    }

    // 何種類のボールがあるか
    int cnt = 0;
    // 回答
    int ans = 0;

    for (int i = 0; i < N; i++) {
        if (Num[i])
            cnt++;
    }

    // 降順にソート
    sort(Num.rbegin(), Num.rend());


    // Numの要素0からK番目以降の和が求めたい答えとなる
    for (int i = K; i < N; i++) {
        ans += Num[i];
    }

    cout << ans << endl;


}
