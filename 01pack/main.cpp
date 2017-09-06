#include <iostream>
using namespace std;


int main()
{
    int dp[1002];
    int v[120];
    int w[120];
    int T,M;
    while(cin>>T>>M&&T>0&&M>0)
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


/*int main()
{
    int dp[102][1002];
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
            dp[0][j] = 0;
        }
        for(int j = 0 ; j<=M; j++)
        {
            dp[j][0] = 0;
        }
        for(int i = 1; i <= M; i++)
        {

            for(int j = 1 ; j<=T; j++)
            {
                if(j>=v[i]&&dp[i-1][j]<dp[i-1][j-v[i]]+w[i])
                {
                    dp[i][j] = dp[i-1][j-v[i]]+w[i];
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        cout<<dp[M][T]<<endl;
    }
    return 0;
}*/
