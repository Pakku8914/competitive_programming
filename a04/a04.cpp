#include <iostream>
using namespace std;
int N;

int main() {
    cin >> N;

    for (int i = 9; i >= 0; i--) {
        // �V�t�g���Z�ɂ����2��i�悷��
        int divi = (1 << i);
        cout << (N / divi) % 2;
    }
    cout << endl;

    return 0;
}