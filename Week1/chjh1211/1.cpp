#include <iostream>
#include <vector>

using namespace std;
int main(void)
{
    vector<int> vec1;

    int sum=0;
    int a;
    for(int i=0;i<9;i++)
    {
        cin >> a;
        sum +=a;
        vec1.push_back(a);
    }
    sum-=100;

    for(int i=0;i<vec1.size();i++)
    {
        for(int j=i+1;j<vec1.size();j++)
        {
            if(vec1[i]+vec1[j]==sum)
            {
<<<<<<< HEAD
                vec1.erase(vec1.erase(vec1.begin()+i));
                vec1.erase(vec1.eras e(vec1.begin()+(j-1)));
=======
                vec1.erase(vec1.begin()+i);
                vec1.erase(vec1.begin()+(j-1));
                break;
>>>>>>> 8ed2c9dc6018530a5e3c72075fb99ba9e89b6cc3
            }
        }
    }
    cout << vec1.size()<<endl;

    for(int i=0;i<vec1.size();i++)
    {
        cout << vec1[i] << endl;
    }

    return 0;
}
