// 주어진 문자열 조각들을 모두 부분 문자열로 포함하는 문자열 중에서 가장 짧은 것 계산

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int k;
string word[15];
int dp[16][(1 << 15) + 1], over[16][16];

int restore(int last, int used) {
	if (used == (1 << k) - 1) return 0;
	int& ret = dp[last][used];
	if (ret != -1) return ret;
	ret = 0;
	for (int next = 0; next < k; ++next) {
		if ((used & (1 << next)) == 0) {
			int cand = over[last][next] + restore(next, used + (1 << next));
			ret = max(ret, cand);
		}	
	}
	return ret;
}

// a와 b는 포함관계가 아니라는 것을 전제로 둠
// 최대 몇글자 겹치는지 계산해주는 함수
// overlap의 합이 최대화 
int overlap(const string& a, const string& b) {
	for (int i = min(a.size(), b.size()); i > 0; --i)
		if (a.substr(a.size() - i) == b.substr(0, i))
			return i;
	return 0;
}

string reconstruct(int last, int used) {
	if (used == (1 << k) - 1) return "";
	for (int next = 0; next < k; ++next) {
		if (used & (1 << next)) continue;
		int ifUsed = restore(next, used + (1 << next)) + over[last][next];
		if (restore(last, used) == ifUsed)
			return (word[next].substr(over[last][next]) + reconstruct(next, used + (1 << next)));
	}
	return "*****ooops*****";
}

int main() {
	int C;
	cin >> C;

	for (int i = 0; i < C; i++) {
		cin >> k;
		for (int j = 0; j < k; j++) {
			cin >> word[j];
		}
		while (true) {
			bool removed = false;
			for (int j = 0; j < k && !removed; ++i)
				for (int r = 0; r < k; ++r)
					if (j != r && word[i].find(word[j]) != -1) {
						// word[j]안에 word[r] 발견한 위치 리턴
						// 없으면 -1리턴
						// -1이 아니면 부분 문자열이 겹치는 의미이므로 삭제함
						word[j] = word[k - 1];
						--k;
						removed = true;
					}
			if (!removed) break;
		}
		for (int i = 0; i < k + 1; ++i)
			for (int j = 0; j < k + 1; ++j)
				over[i][j] = overlap(word[i], word[j]);

		cout << reconstruct(k, 0) << '\n';
	}
}
