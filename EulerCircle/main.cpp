#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;


int main()
{
    int N,M;
    int du[1002];
    while(cin>>N&&N>0)
    {
        cin>>M;
        memset(du,0,sizeof(du));
        for(int i = 0 ; i <M;i++)
        {
            int u,v;
            cin>>u>>v;
            du[u] = !du[u];
            du[v] = !du[v];
        }
        bool flag = false;
        for(int i = 0 ; i <N;i++)
        {
            if(du[i])
            {
                flag = true;
                break;
            }
        }
        if(flag)
        {
            cout<<0<<endl;
        }
        else
        {
            cout<<1<<endl;
        }
    }
}
