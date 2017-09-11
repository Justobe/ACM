#include <iostream>

using namespace std;

int main()
{
    int n;
    int arr [1000];
    cin >> n;
    for(int i = 0 ; i < n; i++)
    {
        cin>>arr[i];
    }
    int j,k;
    for(k=0;k<n-1;k++)
    {
        int sIndex = k;
        int cur = arr[k];
        //找到[k,n-1]最小的数及其下标
        for(j = k;j<n;j++)
        {
            if(arr[j]<cur)
            {
                sIndex = j;
                cur = arr[j];
            }
        }
        //cout<<sIndex<<endl;
        arr[sIndex] = arr[k];
        arr[k] = cur;
    }
    for(int i = 0 ; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
