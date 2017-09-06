#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
int arr[1002];
int dp[1002];
int main()
{
    int tmp;
    int n = 0;
    while(scanf("%d",&tmp)!=EOF)
    {
        arr[n] = tmp;
        n+=1;
    }
    /*memset(dp,0,sizeof(dp));
    int m1 = 0;
    for(int i = 0; i<n; i++)
    {
        dp[i] = 1;
        for(int j = 0; j<i; j++)
        {
            if(arr[j]>arr[i]&&dp[i]<dp[j]+1)
            {
                dp[i] = dp[j]+1;
            }
        }
        if(dp[i]>m1)
            m1 = dp[i];
    }*/
    memset(dp,0,sizeof(dp));
    int m2 = 0;
    for(int i = 0; i<n; i++)
    {
        dp[i] = 1;
        for(int j = 0; j<i; j++)
        {
            if(arr[j]<arr[i]&&dp[i]<dp[j]+1)
            {
                dp[i] = dp[j]+1;
            }
        }
        if(dp[i]>m2)
            m2 = dp[i];
    }
    //cout<<m1<<endl;
    cout<<m2<<endl;

}

