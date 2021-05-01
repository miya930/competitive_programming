#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int N, M;
    cin >> N >> M;

    int a[100], b[100];
    int Num[100] = {0};

    for (int i = 0; i < M; i++)
        cin >> a[i] >> b[i];

    for (int i = 0; i < M; i++) {
        Num[a[i]-1]++; Num[b[i]-1]++;
    }

    int cnt = 0;

    for (int i = 0; i < N; i++) {
        cout << Num[i] << endl;
    }
}
