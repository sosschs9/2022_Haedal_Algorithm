// 쿼드 트리 뒤집기
// 모든 픽셀 검은색 -> b / 모든 픽셀 흰색 -> w 
// 같은 색이 아니면 분할 후에 각각 압축 -> x(1사분면)(2사분면)(3사분면)(4사분면)
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string Data;
int iter = 0;

string reverse() {
	char head = Data[iter];
	iter++;
	if (head == 'b' || head == 'w') 
		return string(1, head);
	else {
		string first = reverse();
		string second = reverse();
		string third = reverse();
		string fourth = reverse();
		// 뒤집은 결과니까 1->3, 2->4, 3->1, 4->2
		return "x" + third + fourth + first + second;
	}
}

int main() {
	int n;
	cin >> n;
	vector<string> res(n, "");

	for (int i = 0; i < n; i++) {
		cin >> Data;
		res[i] = reverse();
		iter = 0;
	}

	for (int i = 0; i < n; i++) {
		cout << res[i];
		if (i != n - 1) cout << endl;
	}
}
