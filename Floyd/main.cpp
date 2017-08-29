#include <iostream>

using namespace std;
const int MAX =99999999;
unsigned int n,e;
int arr[100][100];
void floyd()
{
    for(int k=0; k<n; k++)
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(arr[i][k]<MAX && arr[k][j]<MAX && arr[i][j]>arr[i][k]+arr[k][j])
                    arr[i][j]=arr[i][k]+arr[k][j];
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
            arr[to][from] = dis;
        }
        floyd();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
               cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
        return 0;
    }

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
