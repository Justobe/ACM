#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n;
    while(cin>>n&&n)
    {
        int arr[100002] = {0};
        set<int>myset;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        for(int i = 0;i<n;i++)
        {
            int m = arr[i];
            while(m!=1)
            {
                if(m%2==0)
                {
                    m = m/2;
                    myset.insert(m);
                }
                else
                {
                    m = (m*3 + 1)/2;
                    myset.insert(m);
                }

            }
        }
        int cnt = 0;
        for(int i = n-1;i>=0;i--)
        {
            if(myset.count(arr[i]) == 0)
            {
               if(cnt == 0)
               {
                   cout<<arr[i];
               }
               else
               {
                   cout<<" "<<arr[i];
               }
               cnt++;
            }
        }
        cout<<endl;
    }
    return 0;

}
