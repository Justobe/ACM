#include <iostream>
#include <queue>
#define MAX 1000
using namespace std;
typedef struct Country
{
    double gnum;
    double jnum;
    double grate;
    double jrate;
};
Country cList[MAX];
int rankList[MAX][5];
int flag[MAX] ;
int N,M;
int getRank(int cid,int mid)
{
    if(mid == 1)
    {
        int cnt = 1;
        for(int i = 0; i<N; i++)
        {
            if(i!=cid&&flag[i]==1)
            {
                if(cList[i].gnum>cList[cid].gnum)
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
    else if(mid == 2)
    {
        int cnt = 1;
        for(int i = 0; i<N; i++)
        {
            if(i!=cid&&flag[i]==1)
            {
                if(cList[i].jnum>cList[cid].jnum)
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
    else if(mid == 3)
    {
        int cnt = 1;
        for(int i = 0; i<N; i++)
        {
            if(i!=cid&&flag[i]==1)
            {
                if(cList[i].grate>cList[cid].grate)
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
    else
    {
        int cnt = 1;
        for(int i = 0; i<N; i++)
        {
            if(i!=cid&&flag[i]==1)
            {
                if(cList[i].jrate>cList[cid].jrate)
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
}
int main()
{

    while(cin>>N>>M)
    {
        for(int i = 0 ;i<MAX;i++)
        {
            flag[i] = 0;
        }
        for(int i = 0; i<MAX; i++)
        {
            for(int j = 0 ; j <5; j++)
            {
                rankList[i][j] = 0;
            }
        }
        for(int i = 0; i<N; i++)
        {
            double p;
            cin>>cList[i].gnum>>cList[i].jnum>>p;
            cList[i].grate = cList[i].gnum/p;
            cList[i].jrate = cList[i].jnum/p;
        }
        for(int i = 0; i<M; i++)
        {
            int cid;
            cin>>cid;
            flag[cid] = 1;
            //rcountry.push(cid);
        }
        for(int i = 0; i<N; i++)
        {
            for(int j = 1 ; j <=4; j++)
            {
                if(flag[i] == 1)
                {
                    rankList[i][j] = getRank(i,j);
                }
            }
        }
        for(int k = 0;k<N;k++)
        {
            if(flag[k] == 1)
            {
                int minRank = 999999;
                int mthdId = -1;
                for(int i = 1; i<=4; i++)
                {
                    if(rankList[k][i]<minRank)
                    {
                        mthdId = i;
                        minRank = rankList[k][i];
                    }
                }
                cout<<minRank<<":"<<mthdId<<endl;
            }
        }
        cout<<endl;
    }
    return 0;
}
