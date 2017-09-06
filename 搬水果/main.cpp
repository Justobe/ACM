#include <iostream>
#include <queue>
using namespace std;
priority_queue<int,vector<int>,greater<int> >myqueue;
int n;
int main()
{
    while(cin>>n&&n)
    {
        while(!myqueue.empty())
            myqueue.pop();
        for(int i = 0; i<n; i++)
        {
            int tmp;
            cin>>tmp;
            myqueue.push(tmp);
        }
        int total = 0;
        if(n == 1)
        {
            cout<<myqueue.top()<<endl;
        }
        else
        {
            while(true)
            {
                int a = myqueue.top();
                myqueue.pop();
                int b = myqueue.top();
                myqueue.pop();
                int sum = a + b;
                total+=sum;
                if(myqueue.size() == 0)
                {
                    cout<<total<<endl;
                    break;
                }
                else
                {
                    myqueue.push(sum);
                }
            }
        }
    }
}
