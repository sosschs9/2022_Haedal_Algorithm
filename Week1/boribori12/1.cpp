#include <iostream>
#include <vector>
using namespace std;

int main(void){
    int sum = 0; //모자에 적힌 숫자들의 합을 저장
    int n = 9; // 입력될 9개의 숫자
    vector<int> input (n,0); //9갸의 숫자를 입력받을 vector 선언

    for(int i = 0; i < n; i++){ //index [0] - [9], 9개의 숫자를 입력
        cin >> input[i];
    }

    // for(int i = 0; i < n; i++){ //index [0] - [9], 9개의 숫자가 적절히 들어갔는지 확인
    //     cout << input[i] << " ";
    // }

    vector<int> key;
    for(int i = 0; i < n-1; i++){ //i를 제외하고 나머지를 더한다
        for(int j = i+1; j < n; j++){//j를 제외하고 나머지를 더한다
         key.clear(); //더한 값들이 100이 아닌 경우, 더한 값들의 목록 초기화
         sum = 0; //vector 합 초기화
            for(int k = 0; k < n; k++){
                if(k != i && k != j){ //input[0]부터 [n-1]까지 i와 j를 제외한 나머지를 더한다
                    sum += input[k]; 
                    key.push_back(input[k]); //더한 값들을 저장
                    if(key.size() == 7 && sum == 100){ //더한 값들이 7개이고 그 합이 100이면 반복문 탈출
                        break; 
                    }
                }
            }
            if(key.size() == 7 && sum == 100) break;
        }
        if(key.size() == 7 && sum == 100) break;
    }
    for(int l = 0; l < key.size(); l++){ //더해진 값을 출력
        cout << key[l] << endl;
    }
}
