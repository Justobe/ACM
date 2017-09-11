#include <iostream>
#include <iomanip>
#include <cstdio>
#include <math.h>
using namespace std;

long long getRes(long long n)
{
    if(n == 1)
        return 1;
    else
        return n*getRes(n-1);
}
int main()
{
    long long n;
    while(cin>>n&&n)
    {
        if(n == 1)
            cout<<1<<endl;
        else if (n == 2)
            cout<<2<<endl;
        else
        {

            long long p1 = getRes(n-1)/2;
            long long p2 = 1;
            for(int i = 2*n-1; i >=n+2; i-=1)
            {
                p2*=i;
            }
            long long res = (p2/p1);
            cout<<res<<endl;
        }
    }
    return 0;
}



