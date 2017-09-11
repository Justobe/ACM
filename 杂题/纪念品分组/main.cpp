#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
deque<int>myqueue;
bool cmp(int a,int b)
{
    return a<b;
}
int main()
{
    int w;
    int n;
    cin>>w>>n;
    int arr[30010];
    myqueue.clear();
    int num = 0;
    for(int i = 0 ; i <n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n,cmp);
    for(int i = 0 ; i <n;i++)
    {
        myqueue.push_back(arr[i]);
    }
    while(myqueue.size()>1)
    {
        int large = myqueue.back();
        int small = myqueue.front();
        if(small+large<=w)
        {
            num+=1;
            myqueue.pop_back();
            myqueue.pop_front();
        }
        else
        {
            num+=1;
            myqueue.pop_back();
        }
    }
    if(myqueue.size() == 1)
    {
        num+=1;
    }
    cout<<num<<endl;
    return 0;
}
