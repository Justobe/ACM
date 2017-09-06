#include <iostream>
#include <queue>
using namespace std;
int N;
int ans[22];
bool visited[22];
int arr[22][22];
bool cmp(int a,int b)
{
    return a < b;
}
priority_queue<int, vector<int>, greater<int> >myqueue;
void getPL(int i)
{
    if(i == N+1)
    {
        int cost = 0;
        for(int j = 1;j<=N;j++)
        {
            int person = j;
            int job = ans[j];
            int tmp = arr[person][job];
            cost+= tmp;

        }
        myqueue.push(cost);

    }
    else
    {
        for(int j = 1 ; j<=N;j++)
        {
            if(visited[j] == false)
            {
                visited[j] = true;
                ans[i] = j;
                getPL(i+1);
                visited[j] = false;
            }
        }
    }
}
int main()
{
    while(cin>>N&&N)
    {
        for(int i =1;i<=N;i++)
        {
            for(int j = 1;j<=N;j++)
            {
                cin>>arr[i][j];
            }
        }
        while(!myqueue.empty())
        {
            myqueue.pop();
        }
        getPL(1);
        cout<<myqueue.top()<<endl;
    }
}
