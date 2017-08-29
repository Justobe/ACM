#include <iostream>
#include <queue>
using namespace std;
int n,e;
void BFS(int visited[],int m[][100],int i)
{
    queue<int>myqueue;

    while(!myqueue.empty())
    {
        myqueue.pop();
    }
    myqueue.push(i);
    while(!myqueue.empty())
    {
        int node = myqueue.front();
        myqueue.pop();
        if(visited[node]!=1)
        {
            cout<<node<<" ";
            visited[node] = 1;
        }

        for(int k = 0; k<n; k++)
        {
            if(m[node][k] == 1&&visited[k]!=1)
            {
                myqueue.push(k);
            }
        }
    }

}
int main()
{
    int matrix[100][100];
    int visited[100] = {0};

    cout<<"请输入图的顶点数和边数（顶点从0开始）："<<endl;
    cin>>n>>e;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
                matrix[i][j] = 0;
            else
                matrix[i][j] = -1;
        }
    }

    for(int k=0;k<e;k++)
    {
        int from,to;
        cout<<"请输入第"<<k<<"条边："<<endl;
        cin>>from>>to;
        matrix[from][to] = 1;
        matrix[to][from] = 1;
    }
    BFS(visited,matrix,0);

}
