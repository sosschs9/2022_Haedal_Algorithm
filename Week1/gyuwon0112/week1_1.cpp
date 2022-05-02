#include <iostream>
#include <vector>
using namespace std;

int main() {
	int a[10] = { 0 };
	int sum = 0, sum2 = 0;
	int answer1 = 0, answer2 = 0;

	//9개의 번호 입력
	for (int i = 0; i < 9; i++) {
		cin >> a[i];
		sum += a[i]; //전체 합구하기
	}

	sum2 = sum - 100; 

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (sum2 == a[i] + a[j]) {
				answer1 = i; answer2 = j; //빼야하는 두개의 수의 index 구하기
			}
		}
	}

	for (int i = 0; i < 9; i++) {
		if (i != answer1 && i != answer2) //합이 100이 되는 7개의 수만 출력
			cout << a[i] << "\n";
	}



}
