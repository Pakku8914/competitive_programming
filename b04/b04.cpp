#include <iostream>
#include <string>
using namespace std;

int main() {
    string N;
    int ans = 0;
    cin >> N;

    for (int i = 0; i < N.size(); i++) {
        if (N[i] == '1') {
            ans += (1 << N.size() - 1 - i);
        }
    }
    cout << ans << endl;

    return 0;
}