//출전 선수 구하기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int C; //Case 갯수
    cin >> C;

    vector<int> cnt; //승리 횟수
    for(int i = 0; i < C; i++){
        int win = 0;
        int n; //출전 선수들의 수
        cin >> n;

        vector<int> russia(n);
        for(int j = 0; j < n; j++){ //russia player's rating
            cin >> russia[j];
        }
        sort(russia.begin(), russia.end());
        
        vector<int> korea(n);
        for(int j = 0; j < n; j++){ //korean player's rating
            cin >> korea[j];
        }
        sort(korea.begin(), korea.end());

        int start = 0;
        for(int j = 0; j < n; j++){
            if(russia[start] <= korea[j]){
                start++;
                win++;
            }
        }
        cnt.push_back(win);
    }
    for(int i = 0; i < cnt.size(); i++){
        cout << cnt[i] << endl;
    }
}
