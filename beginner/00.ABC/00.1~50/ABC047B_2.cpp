/***************************/
/**** 2ŸŒ³”z—ñ‚ğ—p‚¢‚½‰ğ ****/
/***************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int W, H, N;
    cin >> W >> H >> N;

    vector<int> x(N), y(N), a(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i] >> a[i];
    }

    vector<vector<int> > Sim(W, vector<int>(H, 0));

    /**** •‚­“h‚é—v‘f‚É'1'‚ğ‘‚«‚Ş ****/
    for (int i = 0; i < N; i++) {
        if (a[i] == 1) {
            for (int j = 0; j < x[i]; j++) {
                for (int k = 0; k < H; k++) {
                    Sim.at(j).at(k) = 1;
                }
            }
        } else if (a[i] == 2) {
            for (int j = x[i]; j < W; j++ ) {
                for (int k = 0; k < H; k++) {
                    Sim.at(j).at(k) = 1;
                }
            }
        } else if (a[i] == 3) {
            for (int j = 0; j < W; j++) {
                for (int k = 0; k < y[i]; k++) {
                    Sim.at(j).at(k) = 1;
                }
            }
        } else if (a[i] == 4) {
            for (int j = 0; j < W; j++) {
                for (int k = y[i]; k < H;k++) {
                    Sim.at(j).at(k) = 1;
                }
            }
        }
   }
   int cnt = 0;

   for (int i = 0; i < W; i++) {
       for (int j = 0; j < H; j++) {
           if (Sim.at(i).at(j) == 0)
                cnt++;
       }
   }
    cout << cnt << endl;
}
