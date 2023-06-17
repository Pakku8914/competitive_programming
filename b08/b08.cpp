#include <iostream>
using namespace std;
#define MAX_N_Q 100000
#define MAX_X_Y 1501

int N, Q;
int field[MAX_X_Y][MAX_X_Y] = { 0 };

int main() {
    int max_x = 0, max_y = 0;
    // ç¿ïWèÄîı
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        field[x][y]++;
        max_x = max(x, max_x);
        max_y = max(y, max_y);
    }

    // ÇQéüå≥ó›êœòaåvéZ
    for (int i = 1; i <= max(max_x, max_y); i++) {
        for (int j = 1; j <= max_y; j++) {
            field[i][j] += field[i][j - 1];
        }
        for (int j = 1; j <= max_y; j++) {
            field[i][j] += field[i - 1][j];
        }
    }

    // èoóÕ
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << field[c][d] + field[a - 1][b - 1] - field[a - 1][d]
            - field[c][b - 1] << endl;
    }
}