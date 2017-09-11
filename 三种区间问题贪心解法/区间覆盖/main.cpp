#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef struct cow
{
    int s;
    int e;
};
cow cows[25010];
bool cmp(const cow a,const cow b)
{
    return a.s<b.s;
}
int N,T;
int main()
{
    while(scanf("%d%d",&N,&T)!=EOF&&N&&T)
    {
        for(int i = 0 ; i <N; i++)
        {
            scanf("%d%d",&cows[i].s,&cows[i].e);
        }
        sort(cows,cows+N,cmp);
        /*for(int i = 0 ;i<N;i++)
        {
            cout<<cows[i].s<<" "<<cows[i].e<<endl;
        }*/
        if(cows[0].s!=1)
        {
            //cout<<-1<<endl;
            printf("-1\n");
        }
        else
        {
            int cur = cows[0].e;
            int maxe = cows[0].e;
            int cnt = 1;
            bool flag;
            while(1)
            {
                flag = false;
                int  i;
                for(i = 0; i<N; i++)
                {
                    //cout<<i<<endl;
                    if(cows[i].s<=cur+1)
                    {
                        if(cows[i].e>maxe)
                        {
                            maxe = cows[i].e;
                            flag = true;
                        }
                    }
                }
                if(flag == false)
                    break;
                else
                {
                    //cout<<i<<" "<<cur<<" "<<maxe<<endl;
                    cur = maxe;
                    cnt++;
                }
            }
            if(cur == T)
                 printf("%d\n",cnt);
            else
                 printf("-1\n");
        }
    }
}
