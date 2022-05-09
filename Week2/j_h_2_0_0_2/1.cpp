#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int Lis(int i, int num, vector<int>& arr, vector<int>& L) {
    if (L[i] != -1) {
        return L[i];
    }

    L[i] = 1;
    for (int j = i + 1; j < num; j++) {
        if (arr[i] < arr[j]) {
            L[i] = max(L[i], Lis(j, num, arr, L) + 1);
        }
    }

    return L[i];
}

int main() {
    int test;
    cin >> test;
    while (test--) {
        int num;
        int maxlen = 0;
        cin >> num;
        vector<int> L(num, -1);
        vector<int> arr(num);

        for (int i = 0; i < num; i++) {
            cin >> arr[i];
        }
        
        for (int i = 0; i < num; i++) {
            maxlen = max(maxlen,Lis(i, num, arr, L));
        }
        cout << maxlen << endl;
    }

    return 0;
}