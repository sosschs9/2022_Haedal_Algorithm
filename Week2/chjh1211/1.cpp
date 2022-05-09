#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>

using namespace std;

vector<int> a;
int cnt;
int n; //원소의 수
void LIS();
vector<int> dp;

int main(void)
{
    int C; //테스트 케이스의 수
    cin >> C;
    for (int i = 0; i < C; i++)
    {
        cin >> n;
        a.resize(n + 1);
        dp.resize(n + 1, 0);

        LIS();
        dp[n] = 1;
        int max = *max_element(dp.begin(), dp.end());
        cout << max << endl;
    }
    return 0;
}
void LIS()
{
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        dp[i] = a[i];
    }
    for (int i = 1; i <n; i++)
    {
        cnt = 1;
        for (int j = i + 1; j <= n; j++)
        {
            if (dp[i] >= a[j])
            {
                dp[i] = cnt;
                break;
            }
            else if (dp[i] < a[j])
            {
                cnt++;
            }
            if (j == n)
            {
                dp[i] = cnt;
                break;
            }
        }
    }
}
