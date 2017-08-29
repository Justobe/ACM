#include <iostream>

using namespace std;

int main()
{
    int n;
    while(cin>>n&&n>0)
    {
        int cnt = 0;
        while(n!=1)
        {
            if(n%2 == 0)
            {
                n = n/2;
                cnt = cnt +1;
            }
            else
            {
                n = n*3+1;
                n = n/2;
                cnt = cnt +1;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
