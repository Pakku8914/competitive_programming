#include <iostream>
using namespace std;
#define MAX_N 100

int N;
int A[MAX_N];
bool ans = false;

void solve() {
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                if (A[i] + A[j] + A[k] == 1000) ans = true;
            }
        }
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    solve();
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}