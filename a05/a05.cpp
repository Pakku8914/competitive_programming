#include <iostream>
using namespace std;
int N, K;
int ans = 0;

int main() {
    cin >> N >> K;
    /*  ©•ª‚Åì¬‚µ‚½•¨
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j++) {
            for (int k = j; k <= N; k++) {
                if (i + j + k == K) {
                    if (i == j && j == k) {
                        ans += 1;
                    }
                    else if (i == j && j != k) {
                        ans += 3;
                    }
                    else if (i != j && j == k) {
                        ans += 3;
                    }
                    else if (i == k && j != i) {
                        ans += 3;
                    }
                    else {
                        ans += 6;
                    }
                    // ans++;
                }
            }
        }
    }
    */

    for (size_t i = 1; i <= N; i++) {
        for (size_t j = 1; j <= N; j++) {
            int diff = K - i - j;
            if (diff <= N && diff >= 1) {
                ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}