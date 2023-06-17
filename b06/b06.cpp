#include <iostream>
using namespace std;
#define MAX_N 100001
int N, Q;
int A[MAX_N][2] = { 0 };
int ans;

void solve(int start, int end) {
    int diff_atari = A[end][1] - A[start - 1][1];
    int diff_hazure = A[end][0] - A[start - 1][0];
    ans = diff_atari - diff_hazure;
}

int main() {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int n;
        cin >> n;
        if (n == 0) {
            A[i][0] += A[i - 1][0] + 1;
            A[i][1] = A[i - 1][1];
        }
        else {
            A[i][1] += A[i - 1][1] + 1;
            A[i][0] = A[i - 1][0];
        }
    }

    cin >> Q;

    for (int i = 0; i < Q; i++) {
        int start, end;
        cin >> start >> end;
        solve(start, end);
        if (ans == 0) {
            cout << "draw" << endl;
        }
        else if (ans < 0) {
            cout << "lose" << endl;
        }
        else {
            cout << "win" << endl;
        }
    }

    return 0;
}
