//회전초밥
//
//
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int k, n, m;
int price[20], pref[20];
int c[201];

int sushi3()
{
	int ret = 0;
	c[0] = 0;
	for (int budget = 1; budget <= m; budget++) {
		int t = 0;
		for (int dish = 0; dish < n; dish++)
			if (budget >= price[dish])
				t = max(t, c[(budget - price[dish]) % 201] + pref[dish]);
		//cout << budget << " " << t << " ret : " << ret << "\n";
		c[budget % 201] = t;
		ret = max(ret, t);
	}
	return ret;
}
int main()
{
	cin >> k;
	while (k--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> price[i] >> pref[i];
			price[i] /= 100;
		}
		m /= 100;
		cout << sushi3() << endl;
	}

}
