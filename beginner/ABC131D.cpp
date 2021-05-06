#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
typedef long long ll;

int main(void)
{
    int N;
    cin >> N;
    vector<ll> A(N), B(N);
    for (int i = 0; i < N; ++i) cin >> A[i] >> B[i];

    //方針：tupleを使用しA[i], B[i], B[i]-A[i]を要素とする配列を作る
    // B[i]-A[i]の値でソート

    vector<tuple<int, int, int> > tup(N);

}
