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
vector<pair<int, int>> russia, korea;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
	return a.second < b.second;
} // pair 두번째를 기준으로 정렬하도록 하는 법

int matchOrder(int n) {
	sort(russia.begin(), russia.end());
	sort(korea.begin(), korea.end());
	
	int cnt = 0, u = 0;
	for (int i = 0; i < n; i++) {
		if (korea[i].first >= russia[u].first) {
			korea[i].second = russia[u].second;
			cnt++;
			u++;
		}	
		else {
			korea[i].second = russia[n - 1].second;
		}
	}
	return cnt;
}

int main() {
	int C, N, maxWin;
	cin >> C; // 테스트 케이스 수

	for (int i = 0; i < C; i++) {
		cin >> N; // 각 팀 선수 인원 수
		russia.assign(N, make_pair(0, 0)); korea.assign(N, make_pair(0, 0));
		// fisrt: rating, second: order
		for (int j = 0; j < N; j++) {
			cin >> russia[j].first;
			russia[j].second = j;
		}
		for (int j = 0; j < N; j++) {
			cin >> korea[j].first;
			korea[j].second = j;
		}
		
		maxWin = matchOrder(N);
		sort(russia.begin(), russia.end(), compare);
		sort(korea.begin(), korea.end(), compare);
		for (int i = 0; i < N; i++) {
			cout << russia[i].first << " ";
		}
		cout << endl;
		for (int i = 0; i < N; i++) {
			cout << korea[i].first << " ";
		}
		cout << endl << maxWin << endl;
	}
}
