#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int N, Q;

    cin >> N;
    vector<int> c(N+1),p(N+1);
    for (int i = 1; i <= N; ++i) cin >> c[i] >> p[i];

    cin >> Q;
    vector<int> l(Q), r(Q);
    for (int i = 0; i < Q; ++i) cin >> l[i] >> r[i];

    // �ݐϘa
    vector<int> s_1(N+1), s_2(N+1);
    s_1[0] = 0; s_2[0] = 0;
    for (int i = 1; i <= N; i++) {
        if(c[i] == 1) {
            s_1[i] = s_1[i-1] + p[i];
            s_2[i] = s_2[i-1]; 
        } else {
            s_1[i] = s_1[i-1];
            s_2[i] = s_2[i-1] + p[i];
        }
    }

    for (int i = 0; i < Q; i++) {
        cout << s_1[r[i]] - s_1[l[i]-1] << ' ' << s_2[r[i]] - s_2[l[i]-1] << endl;
    }
    return 0;
}
