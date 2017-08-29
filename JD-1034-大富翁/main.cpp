#include <iostream>
#include <algorithm>
using namespace std;
int arr[100000+10];
bool cmp(int a,int b)
{
    return a>b;
}
void print(int arr[],int m)
{
    for(int i = 0;i<m; i++)
    {
        if(i!=m-1)
            cout<<arr[i]<<" ";
        else
            cout<<arr[i]<<endl;
    }
}
int main()
{
   int n,m;
   while(cin>>n>>m&&n>0&&m>0)
   {
       for(int i = 0 ; i <n;i++)
       {
           cin>>arr[i];
       }
       sort(arr,arr+n,cmp);
       if(n>=m)
       {
           print(arr,m);
       }
       else
       {
           print(arr,n);
       }
   }
   return 0;
}
