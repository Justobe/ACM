#include <iostream>
#define MAX 1010
using namespace std;
int du[MAX];
int main()
{
    int n,m;
    while(cin>>n&&n)
    {
        cin>>m;
        for(int i = 0;i<MAX;i++)
        {
            du[i] = 0;
        }
        for(int j = 0 ; j<m;j++)
        {
            int a,b;
            cin>>a>>b;
            du[a] = !du[a];
            du[b] = !du[b];

        }
        bool flag = true;
        for(int i = 1;i<=n;i++)
        {
            if(du[i] == 1)
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            cout<<"1"<<endl;
        }
        else
        {
            cout<<"0"<<endl;
        }
    }
}
