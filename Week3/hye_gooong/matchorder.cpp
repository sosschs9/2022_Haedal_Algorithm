// Greedy Algorithm
// 한국팀이 얻을 수 있는 최대 승수 구하기
// 레이팅이 높은 선수가 승리, 레이팅 동일하면 한국팀 승리

// 오름차순 정렬
// 러시아 낮은 선수부터 비교
// 레이팅이 같거나 클 경우 두 선수 매치
// 한국팀 모두 탐색하면 누적 승점 반환

// 만약 매칭 결과를 출력하면?
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> russia, korea;

int matchOrder(int n) {
	sort(russia.begin(), russia.end());
	sort(korea.begin(), korea.end());
	
	int cnt = 0, u = 0;
	for (int i = 0; i < n; i++) {
		if (korea[i] >= russia[u]) {
			cnt++;
			u++;
		}	
	}
	return cnt;
}

int main() {
	int C, N;
	vector<int> maxWin;
	cin >> C; // 테스트 케이스 수
	maxWin.assign(C, 0);

	for (int i = 0; i < C; i++) {
		cin >> N; // 각 팀 선수 인원 수
		russia.assign(N, 0); korea.assign(N, 0);
		for (int j = 0; j < N; j++)
			cin >> russia[j];
		for (int j = 0; j < N; j++)
			cin >> korea[j];
		
		maxWin[i] = matchOrder(N);
	}

	for (int i = 0; i < C; i++)
		cout << maxWin[i] << endl;
}
