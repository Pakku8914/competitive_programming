#include <iostream>
using namespace std;
#define MAX_N 100

int N;
int A[MAX_N];
int X;
bool res = false;

void solve() {
    for (int i : A) {
        if (i == X) {
            res = true;
            return;
        }
    }
}

int main() {
    cin >> N >> X;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    solve();
    if (res) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

    return 0;
}