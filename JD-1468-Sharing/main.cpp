#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <iomanip>
#define MAX 100002
using namespace std;

int nodeList[MAX];
int main()
{
    int s1,s2,N;
    while(cin>>s1>>s2>>N)
    {
        memset(nodeList,0,sizeof(int));
        for(int i = 0 ; i < N; i++)
        {
            int address,next;
            char letter;
            cin>>address>>letter>>next;
            nodeList[address] = next;
        }
        int lena =0,lenb=0;
        int index1 = s1,index2 = s2;
        while(index1!=-1)
        {
            index1 = nodeList[index1];
            lena++;
        }
        while(index2!=-1)
        {
            index2 = nodeList[index2];
            lenb++;
        }
        if(lena > lenb)
        {
            while(lena > lenb)
            {
                s1 = nodeList[s1];
                lena--;
            }
        }
        else
        {
            while(lena < lenb)
            {
                s2 = nodeList[s2];
                lenb--;
            }
        }
        while(s1!=-1&&s2!=-1&&s1!=s2)
        {
            s1 = nodeList[s1];
            s2 = nodeList[s2];
        }
        if(s1 == -1||s2 == -1)
        {
            cout<<"-1"<<endl;
        }
        else
        {
            cout<<setfill('0')<<setw(5)<<s1<<endl;
        }
    }


    return 0;
}
