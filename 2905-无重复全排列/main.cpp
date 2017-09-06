#include <iostream>

using namespace std;
int ans[52];
bool visited[52];
int total;
int N;
void getPL(int i)
{
    if(i == N)
    {
        total += 1;
        for(int j = 0 ; j<N;j++)
        {
            if(j!=N-1)
            {
                cout<<ans[j]<<" ";
            }
            else
            {
                cout<<ans[j]<<endl;
            }
        }
    }
    else
    {
        for(int k = 0 ;k<N;k++)
        {
            if(visited[k] == false)
            {
                visited[k] = true;
                ans[i] = k+1;
                getPL(i+1);
                visited[k] = false;
            }
        }
    }
}
int main()
{

    while(cin>>N&&N)
    {
        for(int i = 0 ; i <52;i++)
        {
            total = 0;
            visited[i] = false;
        }
        getPL(0);
        cout<<"Total="<<total<<endl;
    }
}
