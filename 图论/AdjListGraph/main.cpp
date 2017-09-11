#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 50
using namespace std;

typedef struct AdjNode{
    int vertex;
    struct AdjNode *nextNode;
}AdjNode,*PAdjNode;

typedef struct Node{
    int vertex;
    PAdjNode firstNode;
}Node,*PNode;

typedef struct Graph{
    int n;
    int e;
    PNode adjList;
}ALGraph,*PALGraph;
void createGraph(PALGraph G)
{
    int n,e;
    cout<<"请输入图的顶点数和边数（顶点从0开始）："<<endl;
    cin>>n>>e;
    G->n = n;
    G->e = e;
    for(int i=0;i<n;i++)
    {
        G->adjList[i].vertex = i;
        G->adjList[i].firstNode = NULL;
    }

    for(int j=0;j<G->e;j++)
    {
        cout<<"请输入第"<<j<<"条边："<<endl;
        int startIndex,endIndex;
        cin>>startIndex>>endIndex;
        PAdjNode newNode = (PAdjNode)malloc(sizeof(AdjNode));
        newNode->vertex=endIndex;
        newNode->nextNode = G->adjList[startIndex].firstNode;
        G->adjList[startIndex].firstNode = newNode;
    }
}
int main()
{
    PALGraph G = (PALGraph)malloc(sizeof(ALGraph));
    G->adjList = (PNode)malloc(sizeof(Node)*1000);
    createGraph(G);

    for(int i=0;i<G->n;i++)
    {
        int from = G->adjList[i].vertex;
        PAdjNode temp = G->adjList[i].firstNode;
        while(temp!=NULL)
        {
            int to = temp->vertex;
            cout<<from<<"->"<<to<<endl;
            temp = temp->nextNode;
        }
    }
}
