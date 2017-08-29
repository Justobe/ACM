#include <iostream>
#include <stack>

using namespace std;
unsigned int MAX = 999999;
int main()
{
    unsigned int n,e;
    cin>>n>>e;
    int visited[100];
    int indegree[100];
    for(int i = 0;i<n;i++)
    {
        visited[i] = indegree[i] = 0;
    }
    if(n>0&&e>0)
    {
        int arr[100][100];
        int visited[100] = {0};
        int distance[100];
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
            indegree[to]++;
            //indegree[from]++;
            //arr[to][from] = dis;
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<arr[i][j]<<" ";
            }
            cout<<endl<<endl;
        }

        stack<int>mystack;
        while(!mystack.empty())
        {
            mystack.pop();
        }
        int mycount = 0;
        for(int i = 0;i<n;i++)
        {
            if(indegree[i] == 0)
            {
                mystack.push(i);
            }
        }
        while(!mystack.empty())
        {
            int vectex = mystack.top();
            mycount++;
            mystack.pop();
            visited[vectex] = 1;
            cout<<vectex<<" ";
            for(int i = 0;i<n;i++)
            {
                if(arr[vectex][i]!=MAX)
                {
                    indegree[i]--;
                    if(indegree[i] == 0)
                    {
                        mystack.push(i);
                    }
                }
            }

        }
        if(mycount!=n)
        {
            cout<<"该图中有环"<<endl;
        }
        else
        {
            cout<<"该图中没有环"<<endl;
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
