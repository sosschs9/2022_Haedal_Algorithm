#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int N, K, a;
	cin >> N >> K;
	int rvs_n = 0;
	vector<int> org;

	for (int i = 1; i < K + 1; i++) {
		a = N * i;
		org.push_back(a);
	}
	vector<int> rvs(org.size());
	for (int l = 0; l < org.size(); l++) {
		while (org[l]>0) {
			rvs_n = rvs_n * 10 + org[l] % 10;
			org[l] /= 10;
		}
		rvs[l] = rvs_n;
		rvs_n = 0;
	}
	sort(rvs.begin(), rvs.end());
	cout << rvs[rvs.size()-1];
	return 0;
}
