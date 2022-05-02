#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> midget(9);
	int sum = -100;
	for (int i = 0; i < 9; i++) {
		cin >> midget[i];
		sum += midget[i];
	}

	for (int i = 0; i < 8; i++) {
		for (int j = i+1; j < 9; j++) {
			if (midget[i]+ midget[j] == sum) {
				midget[i] = -1;
				midget[j] = -1;
			}
		}
	}

	for (int i = 0; i < 9; i++) {
		if (midget[i] != -1) {
			cout << midget[i]<<endl;
		}
	}

	
}

