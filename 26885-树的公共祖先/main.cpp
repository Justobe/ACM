#include <iostream>
#include <vector>
#define MAX 1000
using namespace std;
int nodeFather[MAX];
int nodeRank[MAX];
vector<int> child[MAX];
vector<int> query[MAX];
int du[MAX];
int visited[MAX];
int ancester[MAX];
void init()
{
    for(int i = 0 ; i <MAX;i++)
    {
        nodeFather[i] = i;
        nodeRank[i] = 0;
        child[i].clear();
        query[i].clear();
        du[i] = 0;
        visited[i] = 0;
        ancester[i] = 0;
    }
}
int findFather(int x)
{
    int root = x;
    while(root!=nodeFather[root])
    {
        root = nodeFather[root];
    }
    while(x!=root)
    {
        int tmp = nodeFather[x];
        nodeFather[x] = root;
        x = tmp;
    }
    return root;
}

int unite(int x,int y)
{
    int fx = nodeFather[x];
    int fy = nodeFather[y];
    if(nodeRank[fx]<nodeRank[fy])
    {
        nodeFather[fx] = fy;
    }
    else
    {
        nodeFather[fy] = fx;
        if(nodeRank[fx] == nodeRank[fy])
        {
            nodeRank[fy]++;
        }
    }
}

void LCA(int u)
{
    ancester[u] = u;
    int cnum = child[u].size();
    for(int i = 0 ; i <cnum;i++)
    {
        LCA(child[u][i]);
        unite(u,child[u][i]);
        ancester[findFather(u)] = u;
    }
    visited[u] = 1;
    int qnum = query[u].size();
    for(int j = 0 ; j <qnum;j++)
    {
        if(visited[query[u][j]] == 1)
        {
           // cout<<findFather(query[u][j])<<endl;
            //cout<<ancester[findFather(query[u][j])]<<endl;

            return;
        }
    }
}
int main()
{
    int x,y;
    init();
    int a,b;
    while(cin>>a>>b&&a>0&&b>0)
    {
        child[b].push_back(a);
        du[a]++;
    }

    while(cin>>x>>y&&x>0&&y>0)
    {

        query[x].push_back(y);
        query[y].push_back(x);
    }

    for(int i=1; i<=9; i++)
    {
        if(du[i]==0)
        {
            LCA(i);
            break;
        }
    }

    for(int i=1; i<=9; i++)
    {
        cout<<ancester[i]<<" ";
    }
    cout<<endl;
    for(int i=1; i<=9; i++)
    {
        cout<<nodeFather[i]<<" ";
    }
    cout<<endl;
}
/*
2 1
3 2
4 2
5 3
8 5
9 5
6 4
7 4
0 0
1 2
3 4
5 3
5 8
9 1
8 9
0 0*/
