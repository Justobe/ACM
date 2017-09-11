#include <iostream>
#include <queue>
#include <vector>
#include <malloc.h>
#include <stack>
using namespace std;
typedef struct Node
{
    string str;
    int rank;
    int weight;
    int father;
};
struct cmp
{
    bool operator()(Node a,Node b)
    {
        /*if(a.weight>=b.weight)
        {
            if(a.weight>b.weight)
                return true;
            else
                return a.rank>b.rank;
        }
        else
        {
            return false;
        }*/
        if(a.weight = b.weight)
            return a.rank>b.rank;
        else
            return a.weight>b.weight;
    }
};
Node nodeList[100];
priority_queue<Node,vector<Node>,cmp>myque;
int main()
{
    int n;
    while(cin>>n&&n)
    {
        int cur = n;
        while(!myque.empty())
            myque.pop();
        for(int i = 0 ; i <n; i++)
        {
            cin>>nodeList[i].str>>nodeList[i].weight;
            nodeList[i].father = i;
            nodeList[i].rank = i;
            myque.push(nodeList[i]);
        }
        if(n == 1)
        {
            cout<<nodeList[0].str<<":0"<<endl;
        }
        else
        {
            /*while(!myque.empty())
            {
                Node a = myque.top();
                cout<<a.str<<" "<<a.weight<<endl;
                myque.pop();
            }*/
            while(myque.size()>1)
            {
                Node a = myque.top();
                myque.pop();
                Node b = myque.top();
                myque.pop();
                nodeList[cur].str = a.str+b.str;
                nodeList[cur].weight=a.weight+b.weight;
                nodeList[cur].father = cur;
                nodeList[cur].rank = cur;
                nodeList[a.rank].father = cur;
                nodeList[b.rank].father = cur;
                /*if(myque.empty())
                {
                    cur++;
                    break;
                }
                else
                {*/
                myque.push(nodeList[cur]);
                cur++;
                //}
            }
            /*for(int i = 0 ; i<cur;i++)
            {
                cout<<nodeList[i].str<<" "<<nodeList[i].weight<<endl;
            }*/
            for(int i = 0; i<n; i++)
            {
                stack<int>mystack;
                while(!mystack.empty())
                    mystack.pop();
                int ptr = i;
                Node tmp = nodeList[i];
                cout<<tmp.str<<":";
                while(nodeList[ptr].father!=ptr)
                {
                    int fptr = nodeList[ptr].father;
                    string fstr = nodeList[fptr].str;
                    string child = tmp.str;
                    if(fstr.find(child)==0)
                    {
                        mystack.push(0);
                    }
                    else
                    {
                        mystack.push(1);
                    }
                    tmp = nodeList[fptr];
                    ptr = fptr;
                }
                while(!mystack.empty())
                {
                    cout<<mystack.top();
                    mystack.pop();
                }
                cout<<endl;
            }
        }
    }
}
