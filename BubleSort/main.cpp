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
    for(k = 0;k<n-1;k++)
    {
        for(int j = 0 ; j < n-k; j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for(int i = 0 ; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
