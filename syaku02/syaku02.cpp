#include <iostream>
using namespace std;
#define MAX_N 100001

long long int N, K;
long long int s[MAX_N];
long long int cul[MAX_N] = { 1 };

int solve() {
    int r[MAX_N] = { 0 };
    for (int i = 1; i <= N; i++) {
        r[i] = i;
        if (cul[i - 1] == 0) {
            cul[i - 1] = 1;
        }
        while (r[i] <= N && cul[r[i]] / cul[i - 1] <= K) {
            if (cul[r[i]] == 0) {
                r[i] = N;
            }
            r[i]++;
        }
    }
    int cnt_max = 0;
    for (int i = 1; i <= N; i++) {
        cnt_max = max(cnt_max, r[i] - i);
    }
    return cnt_max;
}

int main() {
    cin >> N >> K;

    for (int i = 1; i <= N; i++)cin >> s[i];
    bool check_zero = true;
    for (int i = 1; i <= N; i++) {
        if (i == 1 || s[i - 1] == 0)cul[i] = s[i];
        else if (s[i] == 0 && check_zero) {
            check_zero = false;
            for (int j = 1; j <= i; j++) {
                cul[j] = 0;
            }
        }
        else cul[i] = cul[i - 1] * s[i];
    }

    cout << solve() << endl;
}
