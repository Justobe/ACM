#include <iostream>
#include <algorithm>
using namespace std;
int arr[1002];
bool cmp(const int a,const int b)
{
    return a <= b?true:false;
}
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i = 0;i<n;i++)
        {
            cin>>arr[i];
        }

        sort(arr,arr+n,cmp);
        int sum = 0;
        while(n>=4)
        {
            if(2*arr[0]+arr[n-2]+arr[n-1]>2*arr[1]+arr[0]+arr[n-1])
            {
                sum = sum + 2*arr[1]+arr[0]+arr[n-1];
            }
            else
            {
                sum = sum + 2*arr[0]+arr[n-2]+arr[n-1];
            }
            n = n - 2;
        }
        if(n == 1)
        {
            sum += arr[0];
        }
        if(n == 2)
        {
            sum += arr[1];
        }
        if(n == 3)
        {
            sum = sum + arr[0] + arr[1] + arr[2];
        }
        cout<<sum<<endl;
    }
}
