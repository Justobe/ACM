#include <iostream>

using namespace std;
int arr [1000];
int n;
void SortHeap(int rootindex,int lastindex)
{
    //cout<<rootindex<<endl;
    int biggerindex = rootindex;
    int lChild = 2*rootindex + 1;
    int rChild = 2*rootindex + 2;
    if(rChild<=lastindex)
    {
        if(arr[lChild]>arr[rootindex]||arr[rChild]>arr[rootindex])
        {
            if(arr[lChild]>arr[rChild])
            {
                biggerindex = lChild;
            }
            else
            {
                biggerindex = rChild;
            }
        }
    }
    else if(lChild<=lastindex)
    {
        if(arr[lChild]>arr[rootindex])
        {
            biggerindex = lChild;
        }
    }

    if(biggerindex!=rootindex)
    {
        int temps = arr[biggerindex];
        arr[biggerindex] = arr[rootindex];
        arr[rootindex] = temps;
        //for(int i = 0 ; i < n; i++)
       // {
           // cout<<arr[i]<<" ";
       // }
        //cout<<endl;
        SortHeap(biggerindex,lastindex);
    }
}
void BuildHeap(int n)
{
    //int lastp = (lastindex-1)/2;
    int lastindex = n-1;
    for(int i=(lastindex-1)/2;i>=0;i--)
    {
        SortHeap(i,lastindex);
    }
}
void HeapSort()
{
    int lastindex = n - 1;
    while(lastindex>0)
    {
        int temps = arr[0];
        arr[0] = arr[lastindex];
        arr[lastindex] = temps;
        lastindex--;
        if(lastindex == 0 )
            break;
        SortHeap(0,lastindex);
    }
}
int main()
{

    cin >> n;
    for(int i = 0 ; i < n; i++)
    {
        cin>>arr[i];
    }
    BuildHeap(n);
    HeapSort();
    for(int i = 0 ; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
