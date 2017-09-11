#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int N1,N2;
    priority_queue<long,vector<long>,greater<long> >myqueue;
    while(cin>>N1&&N1>0)
    {
        while(!myqueue.empty())
        {
            myqueue.pop();
        }
        for(int i = 0 ; i <N1; i++)
        {
            int a;
            cin>>a;
            myqueue.push(a);
        }
        cin>>N2;
        for(int i = 0 ; i <N2; i++)
        {
            long a;
            cin>>a;
            myqueue.push(a);
        }
        int cnt = N1+N2;
        int mid;
        if(cnt%2==0)
        {
            mid = cnt/2;
        }
        else
        {
            mid = (cnt+1)/2;
        }
        /*while(!myqueue.empty())
        {
            cout<<myqueue.top()<<" ";
            myqueue.pop();
        }*/
        while(mid>1)
        {
            mid--;
            myqueue.pop();
        }
        long median = myqueue.top();
        cout<<median<<endl;
    }
    return 0;
}
