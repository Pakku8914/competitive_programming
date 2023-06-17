#include <iostream>
using namespace std;
int N;

int main() {
    cin >> N;

    for (int i = 9; i >= 0; i--) {
        // ƒVƒtƒg‰‰Z‚É‚æ‚Á‚Ä2‚Ìiæ‚·‚é
        int divi = (1 << i);
        cout << (N / divi) % 2;
    }
    cout << endl;

    return 0;
}