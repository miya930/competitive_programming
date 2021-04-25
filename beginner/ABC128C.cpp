#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int N, M;
    cin >> N >> M;

    int k[20], s[20][20], p[20];
    
    for (int i = 0; i < M; i++) {
        cin >> k[i];
        for (int j = 0; j < k[i]; j++) {
            cin >> s[i][j];
        }
    }

    for (int i = 0; i < M; i++)
        cin >> p[i];

    

}
