#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> a;

// 2���T����index��Ԃ�(�Ȃ��ꍇ�A-1��Ԃ�)
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

    // b[N]�F�e���������Ԗڂɏ��������m�F���邽�߂̔z��
    sort(b.begin(), b.end());

    for (int i = 0; i < N; i++) {
        c[i] = binary_search(a[i], b);
        cout << c[i] << endl;
    }

    return 0;
}
