#include <iostream>

using namespace std;
int n,m,t;
int si,sj,ei,ej;
int dpi[4] = {-1,0,1,0};
int dpj[4] = {0,1,0,-1};
char myMap[12][12];
bool visited[12][12],flag;
void travel(int T,int i,int j)
{
    if(T==t)
        return;
    for(int l = 0;l<4;l++)
    {
        int tmpi = i + dpi[l];
        int tmpj = j + dpj[l];
        if(visited[tmpi][tmpj] == false&&(myMap[tmpi][tmpj]=='.'||myMap[tmpi][tmpj]=='E'))
        {
            visited[tmpi][tmpj] = true;
            if(myMap[tmpi][tmpj]=='E')
            {
                flag = true;
                return;
            }
            else
            {
                travel(T+1,tmpi,tmpj);
            }
            if(flag)
                return;
            visited[tmpi][tmpj] = false;
        }
    }
}
int main()
{
    while(cin>>n>>m>>t&&n&&m&&t)
    {
        for(int i = 0;i <12;i++)
        {
            for(int j=0;j<12;j++)
            {
                visited[i][j] = false;
            }
        }
        for(int i = 1; i<=n; i++)
        {
            cin>>myMap[i]+1;
            for(int j = 1;j<=m;j++)
            {
                if(myMap[i][j] == 'S')
                {
                    si = i;sj = j;
                }
            }
        }
        flag = false;
        travel(1,si,sj);
        if(flag)
            cout<<"Oh Yes!!!"<<endl;
        else
            cout<<"Tragedy!!!"<<endl;

    }
}
