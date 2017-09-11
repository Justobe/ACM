#include <iostream>
#include <stdlib.h>
using namespace std;
typedef struct Edge{
    int from;
    int to;
    int cost;
}Edge;
Edge edgeList[100];
int cmp(const void*first,const void*second)
{
    return ((Edge*)first)->cost - ((Edge*)second)->cost;
}
int nodeRank[100];
int nodeFather[100];
void Init(int n)
{
    for(int i = 0 ;i<n;i++)
    {
        nodeRank[i] = 0;
        nodeFather[i] = i;
    }
}
int findFather(int x)
{
    int root = x;
    while(nodeFather[root]!=root)
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
    int fatherx = findFather(x);
    int fathery = findFather(y);
    if(nodeRank[fatherx]>nodeRank[fathery])
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

void Kruskal(int n,int e)
{
    int cnt = 0;
    qsort(edgeList,e,sizeof(Edge),cmp);
    /*for(int i = 0 ; i <e;i++)
    {
        cout<<edgeList[i].from<<" "<<edgeList[i].to<<" "<<edgeList[i].cost<<endl;
    }*/
    for(int i = 0 ; i<e&&cnt!=n-1;i++)
    {
        if(findFather(edgeList[i].from)!=findFather(edgeList[i].to))
        {
            cout<<edgeList[i].from<<" "<<edgeList[i].to<<endl;
            unite(edgeList[i].from,edgeList[i].to);
            cnt++;
        }
    }
}
/*
//一种优美的递归形式
int unionsearch(int x)
{
   if(x!=father[x])
   {
        father[x] = find(father[x]);
   }
   return father[x];
}
*/
int main()
{
    cout<<"请输入顶点数和边数："<<endl;
    int n,e;
    cin>>n>>e;

    for(int i = 0 ; i <e;i++)
    {
        cin>>edgeList[i].from>>edgeList[i].to>>edgeList[i].cost;
    }
    Init(n);
    Kruskal(n,e);

    return 0;

/*
7 9
0 1 28
0 5 10
1 2 16
1 6 14
2 3 12
3 4 22
3 6 18
4 5 25
4 6 24

*/
}
