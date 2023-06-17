#include <iostream>
using namespace std;
#define MAX_N 100

int N, K;
int P[MAX_N], Q[MAX_N];
bool res;

void solve() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (P[i] + Q[j] == K) {
                res = true;
                return;
            }
        }
    }
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> P[i];
    for (int i = 0; i < N; i++)
        cin >> Q[i];

    solve();

    if (res) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}