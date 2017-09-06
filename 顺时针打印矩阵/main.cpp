#include <iostream>
#include <stack>
#include <stdlib.h>
using namespace std;
int arr[1003][1003];
int visited[1003][1003];
typedef struct node
{
    int x;
    int y;
}*pnode;
int m,n;
int dir = 0;
stack<pnode>mystack;
void r(int i,int j)
{
    cout<<arr[i][j+1]<<" ";
    visited[i][j+1] = true;
    pnode tmp = (pnode)malloc(sizeof(node));
    tmp->x = i;
    tmp->y = j+1;
    mystack.push(tmp);
}
void d(int i,int j)
{
    cout<<arr[i+1][j]<<" ";
    visited[i+1][j] = true;
    pnode tmp = (pnode)malloc(sizeof(node));
    tmp->x = i+1;
    tmp->y = j;
    mystack.push(tmp);
}
void l(int i,int j)
{
    cout<<arr[i][j-1]<<" ";
    visited[i][j-1] = true;
    pnode tmp = (pnode)malloc(sizeof(node));
    tmp->x = i;
    tmp->y = j-1;
    mystack.push(tmp);
}
void u(int i,int j)
{
    cout<<arr[i-1][j]<<" ";
    visited[i-1][j] = true;
    pnode tmp = (pnode)malloc(sizeof(node));
    tmp->x = i-1;
    tmp->y = j;
    mystack.push(tmp);
}
void printMap()
{
    while(!mystack.empty())
    {
        pnode a = mystack.top();
        mystack.pop();
        int i = a->x;
        int j = a->y;
        if(dir == 2)
        {
            if(j<n&&visited[i][j+1]!=true)
            {
                r(i,j);
            }
            else
            {
                if(i<m&&visited[i+1][j]!=true)
                {
                    dir = 3;
                    d(i,j);
                }
                else
                {
                    break;
                }
            }
        }
        else if(dir == 3)
        {
            if(i<m&&visited[i+1][j]!=true)
            {
                d(i,j);
            }
            else
            {
                if(j>1&&visited[i][j-1]!=true)
                {
                    dir = 4;
                    l(i,j);
                }
                else
                {
                    break;
                }
            }
        }
        else if(dir == 4)
        {

            if(j>1&&visited[i][j-1]!=true)
            {
                l(i,j);
            }
            else
            {
                if(i>1&&visited[i-1][j]!=true)
                {
                    dir = 1;
                    u(i,j);
                }
                else
                {
                    break;
                }
            }
        }
        else if(dir == 1)
        {
            if(i>1&&visited[i-1][j]!=true)
            {
                u(i,j);
            }
            else
            {
                if(j<n&&visited[i][j+1]!=true)
                {
                    dir = 2;
                    r(i,j);
                }
                else
                {
                    break;
                }
            }
        }
    }
}
int main()
{
    while(cin>>m>>n&&m&&n)
    {
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cin>>arr[i][j];
                visited[i][j] = false;
            }
        }
        pnode p = (pnode)malloc(sizeof(node));
        p->x = 1;
        p->y = 1;
        cout<<arr[1][1]<<" ";
        visited[1][1] = true;
        mystack.push(p);
        dir = 2;
        printMap();
        cout<<endl;
    }
}
