#include <iostream>
#include <algorithm>
#define MAX 1000
using namespace std;
typedef struct bg{
    int h;
    int l;
    int t;
};
bg bgList[32];
int dp[1000];
bool cmp(const bg&a,const bg&b)
{
    return a.t < b.t;
}
int main()
{
    int N;
    while(cin>>N&&N>0)
    {
        for(int i = 0;i<N;i++)
        {
            cin>>bgList[i].h>>bgList[i].l>>bgList[i].t;
        }
        for(int i = 0 ; i <MAX;i++)
        {
            dp[i] = 0;
        }
        sort(bgList,bgList+N,cmp);
        int mt = bgList[N-1].t;
        for(int i = 0;i<N;i++)
        {
            for(int j = mt;j>=0;j--)
            {
                if( j <= bgList[i].t && j >= bgList[i].l)
                {
                    if( dp[j] < dp[j-bgList[i].l] + bgList[i].h)
                    {
                        dp[j] = dp[j-bgList[i].l] + bgList[i].h;
                    }
                }
            }
        }
        int hp = 0;
        for(int i = 0;i<=mt;i++)
        {
            if(hp<dp[i])
            hp = dp[i];
        }
        cout<<hp<<endl;
    }
    return 0;
}
