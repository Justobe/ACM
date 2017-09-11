#include <iostream>
#include <string.h>
#define MAX 999999999
using namespace std;
int dp[1010];
int arr[12],dis;
int main()
{
    for(int i = 0 ; i <1010;i++)
        dp[i] = MAX;

    for(int i = 1 ; i <=10;i++)
    {
        cin>>arr[i];
    }
    cin>>dis;
    //dp[1] = arr[1];
    for(int i = 1 ; i <=dis;i++)
    {
        //cout<<"For "<<i<<":--------"<<endl;
        if(i>10)
            dp[i] = dp[i-10]+arr[10];
        else
            dp[i] = arr[i];
        for(int j =1;j<i;j++)
        {
            if(i-j<=10)
            {
                //cout<<"dp[i]"<<dp[i]<<" "<<dp[j]+arr[i-j]<<endl;
                dp[i] = min(dp[j]+arr[i-j],dp[i]);
            }

        }
        //cout<<i<<" "<<dp[i]<<endl;
    }
    cout<<dp[dis]<<endl;
}
