#include <iostream>

using namespace std;

int main()
{
    int n,mid,low,high;
    int arr [1000];
    cin >> n;
    for(int i = 0 ; i < n; i++)
    {
        cin>>arr[i];
    }
    int j,k;
    for(k = 1 ; k < n ; k++)
    {
        if(arr[k]<arr[k-1])
        {
            int cur = arr[k];
            low = 0;
            high = k-1;
            while(low<=high)
            {
                mid = (low + high)/2;
                if(cur>=arr[mid])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
            for(j=k-1; j>=low; j--)
            {
                arr[j+1] = arr[j];
            }
            arr[low] = cur;
        }
        for(int l = 0 ; l < n ; l++)
        {
            cout<<arr[l]<<" ";
        }
        cout<<endl;
   }
   return 0;
}
