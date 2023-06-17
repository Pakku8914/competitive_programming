#include <iostream>
using namespace std;
#define MAX_H_W 1502
int H, W, N;
int field[MAX_H_W][MAX_H_W];

int main() {
    cin >> H >> W >> N;

    // “ü—Í
    for (int i = 0; i < N; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        field[a][b]++;
        field[a][d + 1]--;
        field[c + 1][b]--;
        field[c + 1][d + 1]++;
    }

    // ‚QŸŒ³—İÏ˜a
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            field[i][j] += field[i][j - 1];
        }
        for (int j = 1; j <= W; j++) {
            field[i][j] += field[i - 1][j];
        }
    }

    // o—Í
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            cout << field[i][j] << " ";
        }
        cout << endl;
    }
}
