#include <iostream>

using namespace std;
int getMethod(int m,int n)
{
    if(m == 0||n==1)
    {
        return 1;
    }
    else
    {
        if(n>m)
        {
            return getMethod(m,m);
        }
        else
        {
            return getMethod(m,n-1)+getMethod(m-n,n);
        }
    }
}
int main()
{
    int t,m,n;
    cin>>t;
    for(int i = 0;i<t;i++)
    {
        cin>>m>>n;
        cout<<getMethod(m,n)<<endl;
    }
}
