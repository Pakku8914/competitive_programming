#include <iostream>
using namespace std;
#define MAX_N 100001
int N, K;
int A[MAX_N];
long long int ans = 0;

// しゃくとり法
void solve() {
    int R[MAX_N];
    for (int i = 1; i <= N - 1; i++) {
        if (i == 1)R[i] = 1;
        else R[i] = R[i - 1];

        while (R[i] < N && A[R[i] + 1] - A[i] <= K) {
            R[i] += 1;
        }
    }
    for (int i = 1; i <= N - 1; i++) {
        // 現在の位置からどれぐらい離れているのかを計算
        ans += (R[i] - i);
    }
    cout << ans << endl;
}

int main() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    
    solve();

    return 0;
}