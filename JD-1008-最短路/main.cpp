#include <iostream>
#include <queue>
#define N 1005
#define MAX 9999999
using namespace std;
int arr[N][N];
int brr[N][N];
int dis[N];
int cost[N];
int n,m;
int s,t;
int visited[N];
void spfa(int s)
{
    queue<int>myqueue;
    while(!myqueue.empty())
    {
        myqueue.pop();
    }
    myqueue.push(s);
    while(!myqueue.empty())
    {
        int v = myqueue.front();
        visited[v] = 0;
        myqueue.pop();
        for(int i = 1 ; i <=n; i++)
        {
            if(i!=v&&arr[i][v]!=MAX)
            {
                if(dis[i]>dis[v]+arr[v][i])
                {
                    dis[i] = dis[v] + arr[v][i];
                    cost[i] = cost[v] + brr[v][i];
                    if(visited[i]!=1)
                    {
                        visited[i] = 1;
                        myqueue.push(i);
                    }
                }
                else
                {
                    if(dis[i] = dis[v]+arr[v][i]&&cost[i]>cost[v]+brr[v][i])
                    {
                        cost[i] = cost[v] + brr[v][i];
                    }
                }
            }
        }
    }
}
int main()
{
    while(cin>>n>>m&&n>1&&m>0)
    {
        for(int i = 0 ; i <N; i++)
        {
            dis[i] = MAX;
            cost[i] = MAX;
            visited[i] = 0;
            for(int j = 0; j<N; j++)
            {

                if(i!=j)
                {
                    brr[i][j] = arr[i][j] = MAX;
                }
                else
                {
                    brr[i][j] = arr[i][j] = 0;
                }
            }
        }
        for(int i = 0 ; i <m; i++)
        {
            int a,b,d,p;
            cin>>a>>b>>d>>p;
            arr[a][b] = d;
            arr[b][a] = d;
            brr[a][b] = p;
            brr[b][a] = p;
        }

        cin>>s>>t;
        if(s!=t)
        {
            dis[s] = 0;
            cost[s] = 0;
            visited[s] = 1;
            spfa(s);
            cout<<dis[t]<<" "<<cost[t]<<endl;
        }
    }
    return 0;
}
