#include <iostream>
#include <vector>

using namespace std;
int main(void)
{
    vector<int> vec1;

    int sum=0;
    int a;
    int m,n;
    for(int i=0;i<9;i++)
    {
        cin >> a;
        sum +=a;
        vec1.push_back(a);
    }
    a=sum-100;

    for(int i=0;i<9;i++)
    {
        for(int j=i+1;j<9;j++)
        {
            if(vec1[i]+vec1[j]==a)
            {
                m=i;
                n=j;
            }
        }
    }

    vec1.erase(vec1.begin()+m);
    vec1.erase(vec1.begin()+(n-1));

    for(int i=0;i<vec1.size();i++)
    {
        cout << vec1[i] << endl;
    }

    return 0;
}
