#include <iostream>
#include <queue>
using namespace std;
const int MAX =99999999;
unsigned int n,e;
int arr[100][100];
int visited[100] = {0};
int dis[100];

void spfa()
{
    queue<int> myqueue;
    while(!myqueue.empty())
    {
        myqueue.pop();
    }
    myqueue.push(0);
    while(!myqueue.empty())
    {
        int v = myqueue.front();
        visited[v] = 0;
        myqueue.pop();
        for(int i = 0 ; i<n;i++)
        {
            if(dis[i]>dis[v]+arr[v][i])
            {
                dis[i] = dis[v] + arr[v][i];
                if(visited[i]!=1)
                {
                    visited[i] = 1;
                    myqueue.push(i);
                }
            }
        }
    }
}
int main()
{
    cin>>n>>e;
    if(n>0&&e>0)
    {
        for(int i=0; i<100; i++)
        {
            for(int j=0; j<100; j++)
            {
                if(i!=j)
                    arr[i][j] = MAX;
                else
                    arr[i][j] = 0;
            }
        }
        for(int i=0; i<e; i++)
        {
            int from,to,dis;
            cin>>from>>to>>dis;
            arr[from][to] = dis;
        }
        for(int i = 0; i<n; i++)
        {
            dis[i] = MAX;
        }
        dis[0] = 0;
        visited[0] = 1;
        spfa();
        for(int i = 0; i<n; i++)
        {
            cout<<dis[i]<<" ";
        }
    }
}
