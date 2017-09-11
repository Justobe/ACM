#include <iostream>
using namespace std;


int main()
{
    int dp[1002];
    int v[120];
    int w[120];
    int T,M;
    while(cin >>T>>M&&T>0&&M>0)
    {
        for(int i = 1; i<=M; i++)
        {
            cin>>v[i]>>w[i];
        }
        for(int j = 0; j<=T; j++)
        {
            dp[j] = 0;
        }
        for(int i = 1; i <= M; i++)
        {

            for(int j = 0; j<=T; j++)
            {
                if(j>=v[i]&&dp[j]<dp[j-v[i]]+w[i])
                {
                    dp[j] = dp[j-v[i]]+w[i];
                }
            }
        }
        cout<<dp[T]<<endl;
    }
    return 0;
}
