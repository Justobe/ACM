#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
int n;
int arr[25];
int dp[20000];
int main()
{
    while(cin>>n&&n)
    {
        int sum1 = 0;
        for(int i = 0 ;i<n;i++)
        {
            cin>>arr[i];
            sum1+=arr[i];
        }
        int sum2 = sum1/2;
        //cout<<sum1<<" "<<sum2<<endl;
        memset(dp,0,sizeof(dp));
        for(int i = 0 ; i <n;i++)
        {
            for(int j = sum2;j>=arr[i];j--)
            {
                dp[j] = max(dp[j],dp[j-arr[i]]+arr[i]);
            }
        }
        cout<<abs((2*dp[sum2]-sum1))<<endl;
    }
    return 0;
}
