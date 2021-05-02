#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> a;

// 2分探索でindexを返す(ない場合、-1を返す)
int binary_search(int key, vector<int> A) {
    int left = 0, right = (int)A.size()-1;
    while (right >= left) {
        int mid = (right+left)/2;
        if(A[mid] == key) return mid;
        else if (A[mid] < key) left = mid + 1;
        else if (A[mid] > key) right = mid - 1;
    }
    return -1;
}

int main(void)
{
    int N;
    cin >> N;
    a.assign(N, 0);
    for (int i = 0; i < N; i++) cin >> a[i];

    vector<int> b(N, 0), c(N, 0);
    for (int i = 0; i < N; i++) b[i] = a[i];

    // b[N]：各数字が何番目に小さいか確認するための配列
    sort(b.begin(), b.end());

    for (int i = 0; i < N; i++) {
        c[i] = binary_search(a[i], b);
        cout << c[i] << endl;
    }

    return 0;
}
