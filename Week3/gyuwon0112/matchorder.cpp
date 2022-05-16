//출전 순서 정하기

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int C, N, cnt;

void func(vector<int> russia, vector<int>korea) {
	sort(russia.begin(), russia.end());
	sort(korea.begin(), korea.end());
	int index = 0;
	for (int i = 0; i < N; i++) {
		while (index < N && russia[i] > korea[index]) {
			index++;
		}
		if (index >= N) break;
		index++;
		cnt++;
	}
}

int main() {
	
	cin >> C;
	vector<int>res(C);
	for (int k = 0; k < C; k++) {
		cin >> N;
		cnt = 0;
		vector<int>russia(N);
		vector<int>korea(N);
		for (int i = 0; i < N; i++)
			cin >> russia[i];

		for (int i = 0; i < N; i++)
			cin >> korea[i];
		func(russia, korea);
		res[k] = cnt;
	}
