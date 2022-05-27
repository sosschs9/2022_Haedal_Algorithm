#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int sushi(int n, int m ,vector<int> price, vector<int> need, vector<int> dp)
{
	int res = 0;
	dp[0] = 0;
	for (int budget = 1; budget <= m; budget++) {
		int cand = 0;
		for (int j = 0; j < n; j++) {
			if (price[j] <= budget) {
				cand = max(cand, dp[(budget - price[j]) % 201] + need[j]);
			}
		}
		dp[budget % 201] = cand;
		res = max(res, cand);
	}
	return res;
}
int main()
{
	int C, n, m;
	vector<int> price(21);
	vector<int> need(21);
	vector<int> dp(201);

	cin >> C;
	for(int i=0; i<C; i++){
		cin >> n >> m;
		m /= 100;
		for (int i = 0; i < n; i++) {
			cin >> price[i] >> need[i];
			price[i] /= 100;
		}
		cout << sushi(n, m, price, need,dp) << endl;
	}
}