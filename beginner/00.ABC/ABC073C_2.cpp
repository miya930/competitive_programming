#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int N, ptr = 0, ans = 0;
    int A[100000];

    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];

    sort(A, A+N);
    while(ptr<N) {
        int cc = A[ptr], cnt= 0;
        while (ptr < N && A[ptr] == cc)cnt++,ptr++;   // 同じ数字が出る限り、カウントアップして配列を見ていく
        ans += cnt%2;                                 // ptr今注目している配列要素のIndex
    }

    cout << ans << endl;
}
