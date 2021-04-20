#include <iostream>
using namespace std;

int main(void)
{
    int N;
    cin >> N;

    int d[110];
    for (int i = 0; i < N; i++) cin >> d[i];

    int sum = 0;

    for (int i = 0; i < N;i++) {
        for (int j = i+1; j < N; j++) {
            sum += d[i]*d[j];
        }
    }

    cout << sum << endl;
}
