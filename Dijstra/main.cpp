#include <iostream>

using namespace std;
const int MAX =99999999;
unsigned int n,e;
int arr[100][100];
int visited[100] = {0};
int dis[100];
void Dijkstra()
{
    for(int i = 1; i<n; i++)
    {
        int temp = MAX;
        int newVec = 0;
        for(int j = 1; j<n; j++)
        {
            if(visited[j]==0&&dis[j]<temp)
            {
                newVec = j;
                temp = dis[j];
            }
        }

        visited[newVec] = 1;
        for(int j = 1; j<n; j++)
        {
            if(visited[j] == 0&&arr[newVec][j]<MAX)
            {
                if(dis[j]>dis[newVec]+ arr[newVec][j])
                {
                    dis[j] = dis[newVec]+ arr[newVec][j];
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
            //arr[to][from] = dis;
        }

        /*for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<arr[i][j]<<" ";
            }
            cout<<endl<<endl;
        }*/

        for(int i = 0; i<n; i++)
        {
            dis[i] = arr[0][i];
        }

        /*for(int i = 0; i<n; i++)
        {
            cout<<distance[i]<<" ";
        }*/
        cout<<"Dijkstra TSP"<<endl;
        visited[0] = 1;
        Dijkstra();
        for(int i = 0; i<n; i++)
        {
            cout<<dis[i]<<" ";
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
*/
