#include <iostream>
#include <stdlib.h>
using namespace std;
const int MAX =99999999;
int main()
{
    unsigned int n,e;
    cin>>n>>e;
    if(n>0&&e>0)
    {
        int arr[100][100];
        int nextvex[100] = {0};
        nextvex[0] = -1;
        int lowcost[100] = {0};
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
            arr[to][from] = dis;
            //arr[to][from] = dis;
        }
        for(int j =0;j<n;j++)
        {
            lowcost[j] = arr[0][j];
        }

        /*for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<arr[i][j]<<" ";
            }
            cout<<endl<<endl;
        }*/
        int cnt = 1;
        while(cnt<n)
        {
            int temp = MAX;
            int vertex;
            for(int k = 0;k<n;k++)
            {
                if(nextvex[k]!=-1&&lowcost[k]<temp)
                {
                    temp = lowcost[k];
                    vertex = k;
                }
            }
            cout<<nextvex[vertex]<<"->"<<vertex<<":"<<temp<<endl;
            nextvex[vertex] = -1;
            for(int l = 0;l<n;l++)
            {
                if(arr[vertex][l]<MAX&&nextvex[l]!=-1)
                {
                    lowcost[l] = arr[vertex][l];
                    nextvex[l] = vertex;
                }
            }
            cnt = cnt + 1;

        }
    }
    return 0;
/*
7 9
0 1 28
0 5 10
1 2 16
1 6 14
2 3 12
3 4 22
3 6 18
4 5 25
4 6 24

*/
}
