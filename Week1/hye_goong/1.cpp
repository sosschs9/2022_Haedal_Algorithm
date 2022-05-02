// 백설 공주와 일곱 난쟁이
// 9개의 수 중 합이 100이 되는 7개의 수 찾기
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> arr(9, 0);
	vector<int> res(0, 0);

	// 더하지 않을 2개의 인덱스를 담을 pair
	pair<int, int> num;

	for (int i = 0; i < 9; i++)
		cin >> arr[i];

	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			int total = 0;
			num = { i, j };
			
			for (int k = 0; k < 9; k++)
				if (k != num.first && k != num.second)
					total += arr[k];

			if (total == 100) {
				for (int k = 0; k < 9; k++)
					if (k != num.first && k != num.second)
						res.push_back(arr[k]);
				break;
			}
		}
	}
	
	for (unsigned i = 0; i < res.size(); i++) {
		cout << res[i];
		if (i != res.size() - 1) cout << endl;
	}
}
