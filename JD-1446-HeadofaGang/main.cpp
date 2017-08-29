#include <iostream>
#include <set>
#include <queue>
using namespace std;
typedef struct Edge
{
   int from;
   int to;
   int cost;
};
Edge edgeList[1002];
int getDigit(string name)
{
    return (name[0] - 'A' + 1);
}

string getName(int name)
{
    char c =  name - 1 + 'A';
    char arr[4];arr[0] = c;arr[1] =c;arr[2] = c;arr[3] = '\0';
    string str = arr;
    return str;
}
int nodeRank[27];
int nodeFather[27];
int gangNum[27] ;
int gangHead[27];
int gangSum[27];
int weight[27];
void init()
{
    for(int i = 1 ; i<27;i++)
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
    while(x!=root)
    {
        int father = nodeFather[x];
        nodeFather[x] = root;
        x = father;
    }
    return root;
}

void unite(int x,int y)
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
int main()
{

    int N,K;
    gangNum[27] = {0};
    gangHead[27] = {0};
    gangSum[27] = {0};
    weight[27] = {0};
    cin>>N>>K;
    set<int>person;
    priority_queue< int,vector<int>,greater<int> >gang;
    for(int i = 0 ; i <N;i++)
    {
        string p1,p2;
        int w;
        cin>>p1>>p2>>w;
        edgeList[i].from = getDigit(p1);
        edgeList[i].to = getDigit(p2);
        edgeList[i].cost = w;
        person.insert(edgeList[i].from);
        person.insert(edgeList[i].to);
        weight[edgeList[i].from] += edgeList[i].cost;
        weight[edgeList[i].to] += edgeList[i].cost;
    }


    int n = person.size();
    /*for(int i = 1 ; i <=n;i++)
    {
        cout<<weight[i]<<" ";
    }
    cout<<endl;*/
    init();
    for(int i = 0 ;i <N;i++)
    {
        if(findFather(edgeList[i].from)!=findFather(edgeList[i].to))
        {
            //cout<<edgeList[i].from<<" "<<edgeList[i].to<<endl;
            unite(edgeList[i].from,edgeList[i].to);
        }
    }
    for(int i = 1 ; i <27;i++)
    {
        findFather(i);
    }
    for(int i = 1 ; i<27;i++)
    {
        int number = nodeFather[i];
        gangNum[number]++;
    }

    /*for(int i = 1 ; i <27;i++)
    {
        cout<<gangNum[i]<<" ";
    }
    cout<<endl;*/

    /*for(int i = 1 ; i <27;i++)
    {
        cout<<nodeFather[i]<<" ";
    }
    cout<<endl;*/
    for(int j = 1;j<27;j++)
    {
        if(gangNum[j]>2)
        {
            int sum = 0;
            for(int d = 1; d<27; d++)
            {
                if(nodeFather[d] == j)
                    sum = sum + weight[d];
            }
            gangSum[j] = sum;
            if(sum > 2*K)
            {
                gang.push(j);
            }
        }
    }
    /*for(int i = 1 ; i <=n;i++)
    {
        cout<<gangSum[i]<<" ";
    }
    cout<<endl;*/

    if(gang.size()>0)
    {
        cout<<gang.size()<<endl;
        while(!gang.empty())
        {
            int k = gang.top();
            gang.pop();

            int head = 0;
            int wmax = 0;
            for(int l = 1; l<27; l++)
            {
                if(nodeFather[l] == k)
                {
                    if(weight[l]>wmax)
                    {
                        head = l;
                        wmax = weight[l];
                    }
                }
            }
            string headname = getName(head);
            cout<<headname<<" "<<gangNum[k]<<endl;
        }
    }
    else
    {
        cout<<0<<endl;
    }
    return 0;

    /*

8 70
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10


8 59
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10



8 100
MMM BBB 10
BBB MMM 20
MMM CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10

6 100
MMM BBB 10
BBB MMM 20
MMM CCC 40
DDD EEE 5
EEE DDD 70
DDD BBB 30
    */
}
