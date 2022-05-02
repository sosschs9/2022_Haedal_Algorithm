#include <iostream>
#include <vector>
using namespace std;

int i;

//쿼드트리 뒤집기
string reverseTree(string s) {
	char str = s[i++]; //string 배열을 char로 나누기
	if (str == 'w' || str == 'b')  //모든 픽셀이 b, w -> 그래도 b, w
		return string(1, str); // char -> string
	string upper_left = reverseTree(s); //1사분면
	string upper_right = reverseTree(s); //2사분면
	string lower_left = reverseTree(s); //3사분면
	string lower_right = reverseTree(s); //4사분면

	return "x" + lower_left + lower_right + upper_left + upper_right; // x + 3 + 4+ 1 + 2
	
}

int main() {
	string s;
	int n;
	cin >> n;
	for (int j = 0; j < n; j++) {
		cin >> s;
		i = 0;

		cout << "output : " << reverseTree(s) << "\n";
	}
}
