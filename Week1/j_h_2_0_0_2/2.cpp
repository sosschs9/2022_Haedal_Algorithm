#include <iostream>
#include <vector>
#include <string>
using namespace std;

string quadtree(string s, int &i)
{		
	i++;
	if (s[i] == 'w') {
		return "w";
	}
	if (s[i] == 'b'){
		return "b";
	}

	string allleft = quadtree(s, i);
	string left = quadtree(s, i);
	string right = quadtree(s, i);
	string allright = quadtree(s, i);

	return "x" + right + allright + allleft + left;
}

int main() {
	int n;
	cin >> n;
	string tree;
	for (int i = 0; i < n; i++) {
		int num = -1;
		cin >> tree;
		cout << quadtree(tree, num)<<endl;
	}

}

