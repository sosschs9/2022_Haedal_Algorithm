#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int a = 1;                               //변수선언
	int b = 1;
	int c = 1;
	int len = 0;
	std::cin >> a >> b >> c;
	int p = a * b * c;
	int m = p;
	
	while (m) {                              //len 구하기
		m /= 10;
		len++;
	}
	//벡터선언
	std::vector<int> v(len);                  // p를 넣을 벡터
	std::vector<int> k(10);                   // 0~9까지 갯수 저장할 벡터
	vector<int>::iterator it = v.begin();
	
	while (p) {                               // p 넣는 과정
		it = v.insert(it, p % 10);
		p /= 10;
	}
	for (int j = 0; j < 10; j++) {            // k벡터에 v벡터 내부 숫자 갯수 저장
		for (int i = 0; i < len; i++) {         // 반복문 조건에 왜 len 대신 v.size()를 넣으면 안되는건지..
			if (v[i] == j) {
				k[j]++;
			}
		}
	}
	for (int i = 0; i < 10; i++) {             //자릿수 출력
		cout << k[i] << "\n";
	}
	return 0;
}
