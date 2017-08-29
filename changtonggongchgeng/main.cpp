#include <iostream>
#include <algorithm>
using namespace std;
typedef struct Edge{
    int from;
    int to;
    int cost;
};
Edge edgeList[102];
int nodeRank[102];
int nodeFather[102];
int N,M;
bool cmp(const Edge &a,const Edge &b)
{
    return a.cost <b.cost?true:false;
}
void init()
{
    for(int i = 0;i<M;i++)
    {
        nodeFather[i] = i;
        nodeRank[i] = 0;
    }
}

int findFathner(int x)
{
    int root = x;
    while(nodeFather[root]!= root)
    {
        root = nodeFather[root];
    }
    while(x!=root)
    {
        int father = nodeFather[x];
        nodeFather[x] = root;
        x = father;
    }
    return root;
}

int unite(int x,int y)
{
    int fatherx = findFathner(x);
    int fathery = findFathner(y);
    if(nodeRank[fatherx] > nodeRank[fathery])
    {
        nodeFather[fathery] = fatherx;
    }
    else
    {
        nodeFather[fatherx] = fathery;
        if(nodeRank[fatherx] == nodeRank[fathery])
        {
            nodeRank[fathery]++;
        }
    }
}
int main()
{
    while(cin>>N&&N>0)
    {
        cin>>M;
        for(int i = 0;i<N;i++)
        {
           cin>>edgeList[i].from>>edgeList[i].to>> edgeList[i].cost;
        }
        sort(edgeList,edgeList+N,cmp);
        int cnt = 0;
        int cost = 0;
        init();
        for(int j = 0 ; j<N&&cnt != M-1;j++)
        {
            int from = edgeList[j].from;
            int to = edgeList[j].to;
            if(findFathner(from)!=findFathner(to))
            {
                unite(from,to);
                cnt = cnt +1;
                cost = cost + edgeList[j].cost;
            }
        }
        if(cnt!=M-1)
        {
            cout<<"?"<<endl;
        }
        else
        {
            cout<<cost<<endl;
        }
    }
    return 0;
}
