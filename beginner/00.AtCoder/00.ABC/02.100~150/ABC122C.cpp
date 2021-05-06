#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
    int N, Q;
    string S;
    cin >> N >> Q >> S;
    vector<int> l(N), r(N);
    for (int i = 0; i < Q; i++) cin >> l[i] >> r[i];

    // S��i�Ԗڂ̕�����A,C,G,T�̂����ꂩ�ł���� 1, ����ȊO�ł���� 0
    vector<int> a(N+1, 0);
    for (int i = 1; i < N; i++) {
        if (S[i-1] == 'A' && S[i] == 'C') {     // 0origin���Ƃ킩��ɂ����̂�a[i], sum[i]��1origin�ōl����B
            a[i+1] = 1;
        }
    }
    
    // �ݐϘa
    vector<int> sum(N+1, 0);
    for (int i = 1; i <= N; i++) sum[i] = sum[i-1] + a[i];

    for (int i = 0; i < Q; i++) {
        cout << sum[r[i]] - sum[l[i]] << endl;
    }
    
    return 0;
}
