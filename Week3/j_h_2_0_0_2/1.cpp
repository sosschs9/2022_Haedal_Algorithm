#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n;
    int count=0;
	int money[6] = {500,100,50,10,5,1};
	cin>>n;
	n=1000-n;
	for(int i=0;i<6;i++){
		count+=n/money[i];
		n%=money[i];	
	}
	cout<<count<<endl;
}
