#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;

typedef struct Node{
int address;
char val;
int next;
};
int main()
{
    int address1,address2,nodeNum;
    while(scanf("%d%d%d",address1,address2,nodeNum)!=EOF)
    {
        if(nodeNum!=0)
        {
            map<int,node>map1;
            map<int,node>map2;
            for(int i = 0;i<nodeNum;i++)
            {
                int address,next;
                char val;
                scanf("%d%c%d",address,val,next);
                Node newNode;
                newNode.address = address;
                newNode.val = val;
                newNode.next = next;
                map1.insert(pair<int,Node>(address,newNode));
                map2.insert(pair<int,Node>(next,newNode));
            }
            int laddress1,int laddress2;
            map<int,node>map1::iterator iter;
            for(iter = map1.begin();iter!=map1.end();iter++)
            {
                if(iter->second.next == -1)
                {

                }
            }
        }
    }
}
