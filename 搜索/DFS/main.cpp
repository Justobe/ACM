#include <iostream>

using namespace std;
int n,e;
void DFS(int visited[],int m[][100],int i)
{
    if(visited[i]!=1)
    {
        cout<<i<<" ";
        visited[i] = 1;
        for(int k = 0;k<n;k++)
        {
            if(m[i][k]!=-1)
            {
                DFS(visited,m,k);
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

    /*for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
           cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }*/
    DFS(visited,matrix,0);



}
