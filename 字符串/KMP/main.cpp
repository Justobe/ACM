#include <iostream>
#include <string.h>
using namespace std;
int next[100] = {0};
void getNext(string str)
{
    next[0] = 0;
    int index;
    int maxlen;
    int len = str.length();
    for(int i = 1,k = 0;i<len;i++)
    {
        while(k>0&&str[i]!=str[k])
        {
            k = next[k-1];
        }
        if(str[k] == str[i])
        {
            k++;
        }
        next[i] = k;
    }

}
void kmp(string src,string trgt)
{
    int slen = src.length();
    int tlen = trgt.length();
    for(int i = 0,q = 0;i<slen;i++)
    {
        while(q>0&&trgt[q]!=src[i])
        {
            q = next[q-1];
        }
        if(trgt[q] == src[i])
        {
            q++;
        }
        if(q == tlen)
        {
            cout<<"Pattern occurs with shift:"<< i-tlen+1<<endl;
            return;
        }
    }
}
int main()
{
    string src = "ABCDABCDABD";
    string trgt = "ABCDABD";
    getNext(trgt);
    kmp(src,trgt);
}
