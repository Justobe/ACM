#include <iostream>
using namespace std;


int main()
{
    int dp[33000];
    int v[10002];
    int w[10002];
    int T,M;
    while(cin >>M>>T&&T>0&&M>0)
    {
        for(int i = 1; i<=M; i++)
        {
            cin>>v[i];
            w[i] = v[i];
        }
        for(int j = 0; j<=T; j++)
        {
            dp[j] = 0;
        }
        for(int i = 1; i <= M; i++)
        {

            for(int j = T; j>=0; j--)
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
