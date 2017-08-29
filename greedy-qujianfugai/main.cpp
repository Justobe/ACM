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
    int arr[1000];
    cin>>n>>k;
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n,cmp);
    int cur = arr[0];
    int cnt =0;
    for(int i = 1;i<n;i++)
    {
       if(arr[i] - cur > k)
       {
           cur = arr[i];
           cnt = cnt + 1;
       }
    }
    cout <<cnt + 1<<endl;

}
