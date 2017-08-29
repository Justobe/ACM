#include <iostream>
#include <algorithm>
#define MAX 999999
using namespace std;
int nodeFather[102];
int nodeRank[102];
typedef struct Edge{
    int from;
    int to;
    int status;
    int cost;
};
Edge edgeList[5000];
bool cmp(const Edge &a,const Edge&b)
{
    return a.cost<b.cost;
}
void init(int n)
{
    for(int i = 1;i<=n;i++)
    {
        nodeFather[i] = i;
        nodeRank[i] = 0;
    }
}

int findFather(int x)
{
    int root = x;
    while(nodeFather[root]!=root)
    {
        root = nodeFather[root];
    }
    while(root!=x)
    {
        int tmp = nodeFather[x];
        nodeFather[x] = root;
        x = tmp;
    }
    return root;
}

void unite(int x,int y)
{
    int fx = findFather(x);
    int fy = findFather(y);
    if(fx!=fy)
    {
        if(nodeRank[fx]>nodeRank[fy])
        {
            nodeFather[fy] = fx;
        }
        else
        {
            nodeFather[fx] = fy;
            if(nodeRank[fx] == nodeRank[fy])
            {
                nodeRank[fy]++;
            }
        }
    }
}
int main()
{
    int N;
    while(cin>>N&&N)
    {
        init(N);
        int edgeCnt = (N-1)*N/2;
        int cnt = 0;
        for(int i = 0 ; i <edgeCnt;i++)
        {
            cin>>edgeList[i].from>>edgeList[i].to>>edgeList[i].cost>>edgeList[i].status;
            if(edgeList[i].status == 1)
            {
                unite(edgeList[i].from,edgeList[i].to);
            }
        }
        sort(edgeList,edgeList+edgeCnt,cmp);

        int cost = 0;
        for(int i = 0;i<edgeCnt&&cnt<N-1;i++)
        {
            int u = edgeList[i].from;
            int v = edgeList[i].to;
            if(edgeList[i].status == 0&&findFather(u)!=findFather(v))
            {
                unite(u,v);
                cost+=edgeList[i].cost;
            }
        }
        cout<<cost<<endl;
    }
    return 0;
}
