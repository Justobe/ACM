#include <iostream>

using namespace std;
void MergeArr(int arr[],int startindex,int mid,int endindex,int temp[])
{
    int ptr1 = startindex;
    int ptr2 = mid+1;
    int ptr3 = 0;
    while(ptr1<=mid&&ptr2<=endindex)
    {
        if(arr[ptr1]<arr[ptr2])
        {
            temp[ptr3++] = arr[ptr1++];
        }
        else
        {
            temp[ptr3++] = arr[ptr2++];
        }
    }
    while(ptr1<=mid)
    {
        temp[ptr3++] = arr[ptr1++];
    }
    while(ptr2<=endindex)
    {
        temp[ptr3++] = arr[ptr2++];
    }
    for(int i = 0 ; i<ptr3;i++)
    {
        arr[i+startindex] = temp[i];
    }

}
void MergeSort(int arr[],int startindex,int endindex,int temp[])
{
    if(startindex<endindex)
    {
        int mid = (startindex + endindex)/2;
        MergeSort(arr,startindex,mid,temp);
        MergeSort(arr,mid+1,endindex,temp);
        MergeArr(arr,startindex,mid,endindex,temp);
    }
}
int main()
{
    int n;
    int arr[1000];
    int temp[1000];
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        cin>>arr[i];
    }

    MergeSort(arr,0,n-1,temp);

    for(int i = 0 ; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}
