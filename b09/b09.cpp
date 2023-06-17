#include <iostream>
using namespace std;
#define MAX_X_Y 1502
int N;
int field[MAX_X_Y][MAX_X_Y];
int ans = 0;

int main() {
    // ì¸óÕ
    cin >> N;
    int max_x = 0, max_y = 0;
    for (int i = 0; i < N; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        field[a][b]++;
        field[c][d]++;
        field[a][d]--;
        field[c][b]--;
        max_x = max(max_x, c);
        max_y = max(max_y, d);
    }

    // 2éüå≥ó›êœòa
    for (int i = 0; i <= max_x; i++) {
        for (int j = 0; j <= max_y; j++) {
            field[i][j] += field[i][j - 1];
        }
        if (i == 0) continue;
        for (int j = 0; j <= max_y; j++) {
            field[i][j] += field[i - 1][j];
        }
    }

    // èoóÕ
    for (int i = 0; i <= max_x; i++) {
        for (int j = 0; j <= max_y; j++) {
            if (field[i][j] > 0) ans++;
        }
    }
    cout << ans << endl;
}