#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// �u�z�� A �ɂ���J�[�h���炢�����I�񂾂Ƃ��̍��v�v�Ƃ��čl��������̂��
// �r�b�g�S�T�����g��
vector<long long> Enumerate(vector<long long> A) {
	// �v�Z���ʂ�ۑ�����z��
	vector<long long> SumList;
	// �r�b�g�S�T��
	for (int i = 0; i < (1 << A.size()); i++) {
		long long sum = 0; // ���݂̍��v�l
		for (int j = 0; j < A.size(); j++) {
			if (i & (1 << j)) sum += A[j];
		}
		SumList.push_back(sum);
	}
	return SumList;
}

// ����
long long N, K;
long long A[39];

int main() {
	// ����
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> A[i];

	// �J�[�h�𔼕����ɕ�����
	vector<long long> L1, L2;
	for (int i = 1; i <= N / 2; i++) L1.push_back(A[i]);
	for (int i = N / 2 + 1; i <= N; i++) L2.push_back(A[i]);

	// ���ꂼ��ɂ��āA�u���蓾��J�[�h�̍��v�v��S��
	vector<long long> Sum1 = Enumerate(L1);
	vector<long long> Sum2 = Enumerate(L2);
	// �\�[�g
	sort(Sum1.begin(), Sum1.end());
	sort(Sum2.begin(), Sum2.end());

	// �񕪒T���� Sum1[i] + Sum2[j] = K �ƂȂ���̂����݂��邩��������
	for (int i = 0; i < Sum1.size(); i++) {
		// �񕪒T��
		int pos = lower_bound(Sum2.begin(), Sum2.end(), K - Sum1[i]) - Sum2.begin();
		// �����Ɉ��������������H && �������H
		if (pos < Sum2.size() && Sum2[pos] == K - Sum1[i]) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}