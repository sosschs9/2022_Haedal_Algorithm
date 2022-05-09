#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;
vector<int> cache;
string str;

int cal(int start, int end) {
	bool lev[4] = { true, true, true, true };
	vector<int> intStr;
	for (int i = start; i < end; i++) {
		intStr.push_back(int(str[i]));
	}

	// 난이도: 1
	for (int i = 0; i < intStr.size()-1; i++) {
		if (intStr[i] != intStr[i + 1]) {
			lev[0] = false; break;
		}
	}
	if (lev[0]) return 1;

	// 난이도: 2
	for (int i = 0; i < intStr.size() - 1; i++) {
		if (intStr[i] + 1 != intStr[i + 1]) {
			lev[1] = false; break;
		}
	}
	if (lev[1]) return 2;
	lev[1] = true;
	for (int i = 0; i < intStr.size() - 1; i++) {
		if (intStr[i] - 1 != intStr[i + 1]) {
			lev[1] = false; break;
		}
	}
	if (lev[1]) return 2;

	// 난이도: 4
	int n1 = intStr[0];
	int n2 = intStr[1];
	for (int i = 2; i < intStr.size(); i++) {
		if (i % 2 == 0) {
			if (intStr[i] != n1) {
				lev[2] = false; break;
			}
		}
		else {
			if (intStr[i] != n2) {
				lev[2] = false; break;
			}
		}
		
	}
	if (lev[2]) return 4;

	// 난이도: 5
	int d = intStr[1] - intStr[0];
	for (int i = 0; i < intStr.size()-1; i++) {
		if (intStr[i+1] - intStr[i] != d) {
			lev[3] = false; break;
		}
	}
	if (lev[3]) return 5;

	// 그 외의 경우 난이도
	return 10;
}

int pi(int start) {
	if (start == str.size()) return 0;
	int& ret = cache[start];
	if (ret != -1) return ret;
	// str 10
	ret = INF;
	for (int L = 3; L <= 5; L++) {
		if (start + L <= str.size()) {
			ret = min(cal(start, start + L) + pi(start + L), ret);
		}
	}
	return ret;
}

int main() {
	int C;
	cin >> C;
	vector<int> level;
	level.assign(C, 0);
	
	for (int i = 0; i < C; i++) {
		cin >> str;
		cache.assign(str.size(), -1);
		level[i] = pi(0);
	}

	for (int i = 0; i < C; i++) {
		cout << level[i];
		if (i != C - 1) cout << endl;
	}
}
