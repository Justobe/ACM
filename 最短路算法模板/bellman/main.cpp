#include <iostream>
#include <stdlib.h>
using namespace std;
const int MAX =99999999;
typedef struct Edge{
    int from,to;
    int val;
}Edge;
Edge edge[1000];
unsigned int n,e;
int dis[100];
bool Bellman()
{
    for(int i = 0; i<n-1; i++)
    {
        for(int j = 0; j<e; j++)
        {

            if(dis[edge[j].to]>dis[edge[j].from]+edge[j].val)
            {
                dis[edge[j].to] = dis[edge[j].from]+edge[j].val;
            }
        }
    }
    bool flag = true;
    for(int k = 0 ; k < e; k++)
    {
        if(dis[edge[k].to]>dis[edge[k].from]+edge[k].val)
        {
            flag = false;
            break;
        }
    }
    return flag;
}
int main()
{

    cin>>n>>e;
    if(n>0&&e>0)
    {
        for(int i = 1;i<n;i++)
        {
            dis[i] = MAX;
        }
        dis[0] = 0;
        for(int i=0; i<e; i++)
        {
            int from,to,dis;
            cin>>from>>to>>dis;
            edge[i].from = from;
            edge[i].to = to;
            edge[i].val = dis;
            //arr[to][from] = dis;
        }

        for(int i = 0; i<e; i++)
        {
            if(edge[i].from == 0)
            {
                dis[edge[i].to] = edge[i].val;
            }
        }

        for(int i = 0; i<n; i++)
        {
            cout<<dis[i]<<" ";
        }
        cout<<"Bellman-Ford最短路："<<endl;
        bool flag = Bellman();
        if(flag)
        {
            for(int i = 0; i<n; i++)
            {
                cout<<dis[i]<<" ";
            }
        }
        else
        {
            cout<<"存在负环"<<endl;
        }


    }
    return 0;
}

/*
5 7
0 1 10
0 3 30
0 4 100
1 2 50
2 4 10
3 2 20
3 4 60

5 7
0 1 10
0 4 100
1 2 50
2 3 -2
3 0 -1
3 4 -6
4 2 -1
*/
