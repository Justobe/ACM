#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(const int &a,const int &b)
{
    return a<=b ? true:false;
}
int main()
{
    int n,k;
    int arr[10000];
    while(cin>>n>>k&&n&&k)
    {
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        if(n == 1)
            cout<<1<<endl;
        else
        {
            sort(arr,arr+n,cmp);
            int cur = arr[0]+k;
            int cnt = 1;
            for(int i=0; i<n; i++)
            {
                if(arr[i]>cur)
                {
                    if(arr[i]+k>=arr[n-1])
                    {
                        cnt+=1;
                        break;
                    }
                    else
                    {
                        cur=arr[i]+k;
                        cnt+=1;
                    }
                }
            }
            cout<<cnt<<endl;
        }
    }
}
