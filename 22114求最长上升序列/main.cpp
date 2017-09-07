#include <iostream>
#include <string.h>
#include <stack>
using namespace std;
int n;
int dp[1010];
int pre[1010];
int arr[1010];
stack<int>mystack;
int main()
{
    while(cin>>n&&n)
    {
        for(int i = 0 ; i <n;i++)
        {
            cin>>arr[i];
        }
        while(!mystack.empty())
        {
            mystack.pop();
        }
        memset(dp,0,sizeof(int));
        memset(pre,0,sizeof(int));
        int m = 0;
        int mindex = -1;
        for(int i = 0 ; i<n;i++)
        {
            dp[i] = 1;
            pre[i] = i;
            for(int j = 0;j<i;j++)
            {
                if(arr[i]>arr[j]&&dp[i]<dp[j]+1)
                {
                    dp[i] = dp[j]+1;
                    pre[i] = j;
                }
            }
            //m = max(m,dp[i]);
            if(m<dp[i])
            {
                m = dp[i];
                mindex = i;
            }

        }

        cout<<"max="<<m<<endl;
        while(pre[mindex]!=mindex)
        {
            mystack.push(arr[mindex]);
            mindex = pre[mindex];
        }
        mystack.push(arr[mindex]);
        while(!mystack.empty())
        {
            if(mystack.size()==1)
            {
                cout<<mystack.top()<<endl;
                mystack.pop();
            }
            else
            {
                cout<<mystack.top()<<" ";
                mystack.pop();
            }
        }
    }

}

