#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int Lis(int i, int num, vector<int>& arr, vector<int>& L) {
	if (L[i + 1] != -1) {
		return L[i + 1];
	}

	L[i + 1] = 0;
	for (int j = i + 1; j < num; j++) {
		if (i == -1 || arr[i] < arr[j]) {
			L[i + 1] = max(L[i + 1], Lis(j, num, arr, L) + 1);
		}
	}

	return L[i + 1];
}

int main() {
	int test;
	cin >> test;
	while (test--) {
		int num;
		int maxlen = 0;
		cin >> num;
		vector<int> L(num + 1, -1);
		vector<int> arr(num + 1);

		for (int i = 0; i < num; i++) {
			cin >> arr[i];
		}


		cout << Lis(-1, num, arr, L) << endl;
	}

	return 0;
}