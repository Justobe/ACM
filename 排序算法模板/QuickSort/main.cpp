#include <iostream>

using namespace std;

int partion(int arr[],int low,int high)
{
    //arr[0] = arr[low];
    while(low<high)
    {
        while(low<high&&arr[high]>=arr[low])
            high--;
        int temp1 = arr[low];
        arr[low] = arr[high];
        arr[high] = temp1;
        while(low<high&&arr[low]<=arr[high])
            low++;
        int temp2 = arr[low];
        arr[low] = arr[high];
        arr[high] = temp2;
    }
    //arr[low] = arr[0];
    return low;
}

int QuickSort(int arr[],int low,int high)
{
    int flag = partion(arr,low,high);
    if(low<high)
    {
        QuickSort(arr,low,flag-1);
        QuickSort(arr,flag+1,high);
    }
}
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
    QuickSort(arr,0,n);
    for(int i = 0 ; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
