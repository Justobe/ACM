#include <iostream>
using namespace std;


int main()
{
    int dp[6002];
    int v[502];
    int w[502];
    int num[502];
    int n,m;
    while(cin >>n>>m&&n>0&&m>0)
    {
        for(int i = 1; i<=n; i++)
        {
            cin>>v[i]>>w[i]>>num[i];
        }
        for(int j = 0; j<=m; j++)
        {
            dp[j] = 0;
        }
        for(int i = 1; i <= n; i++)
        {
            for(int k = 0; k<num[i]; k++)
            {
                for(int j = m; j>=0; j--)
                {
                    if(j>=v[i]&&dp[j]<dp[j-v[i]]+w[i])
                    {
                        dp[j] = dp[j-v[i]]+w[i];
                    }
                }
            }
        }
        cout<<dp[m]<<endl;
    }
    return 0;
}
