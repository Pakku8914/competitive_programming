#include <iostream>
using namespace std;
#define MAX_H_M 1501

// “ü—Í
int H, W, Q;
int X[MAX_H_M][MAX_H_M];
int ans = 0;

int main() {
    cin >> H >> W;
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            int temp;
            cin >> temp;
            X[i][j] = X[i][j - 1] + temp;
        }
        for (int j = 1; j <= W; j++) {
            X[i][j] = X[i - 1][j] + X[i][j];
        }
    }
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        ans = 0;
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        ans = X[a - 1][b - 1] + X[c][d] - X[a - 1][d] - X[c][b - 1];
        cout << ans << endl;
    }
}