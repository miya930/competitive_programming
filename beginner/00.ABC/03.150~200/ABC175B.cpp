#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int N;
    cin >> N;

    vector<int> L(N);
    for (int i = 0; i < N; i++) cin >> L[i];

    int ans = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < j; k++) {
                if((i==j) || (j==k) || (i==k))
                    continue;
                if((L[i]==L[j])||(L[j]==L[k])||(L[i]==L[k]))
                    continue;
                if (((L[i]+L[j])>L[k]) && ((L[i]+L[k])>L[j]) && ((L[j]+L[k]) > L[i]))
                    ans++;
            }
        }
    }
    cout << ans << endl;
}
