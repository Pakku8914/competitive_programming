#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 「配列 A にあるカードからいくつか選んだときの合計」として考えられるものを列挙
// ビット全探索を使う
vector<long long> Enumerate(vector<long long> A) {
	// 計算結果を保存する配列
	vector<long long> SumList;
	// ビット全探索
	for (int i = 0; i < (1 << A.size()); i++) {
		long long sum = 0; // 現在の合計値
		for (int j = 0; j < A.size(); j++) {
			if (i & (1 << j)) sum += A[j];
		}
		SumList.push_back(sum);
	}
	return SumList;
}

// 入力
long long N, K;
long long A[39];

int main() {
	// 入力
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> A[i];

	// カードを半分ずつに分ける
	vector<long long> L1, L2;
	for (int i = 1; i <= N / 2; i++) L1.push_back(A[i]);
	for (int i = N / 2 + 1; i <= N; i++) L2.push_back(A[i]);

	// それぞれについて、「あり得るカードの合計」を全列挙
	vector<long long> Sum1 = Enumerate(L1);
	vector<long long> Sum2 = Enumerate(L2);
	// ソート
	sort(Sum1.begin(), Sum1.end());
	sort(Sum2.begin(), Sum2.end());

	// 二分探索で Sum1[i] + Sum2[j] = K となるものが存在するかを見つける
	for (int i = 0; i < Sum1.size(); i++) {
		// 二分探索
		int pos = lower_bound(Sum2.begin(), Sum2.end(), K - Sum1[i]) - Sum2.begin();
		// 検索に引っかかったか？ && 答えか？
		if (pos < Sum2.size() && Sum2[pos] == K - Sum1[i]) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}