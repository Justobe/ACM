#include <iostream>
#include <algorithm>
using namespace std;
typedef struct activity{
    int start;
    int finish;
};
activity arr[10002];

bool cmp(const activity &a,const activity &b)
{
    return a.finish <= b.finish ? true:false;
}
int main()
{
    int n;
    int m;
    cin>>m;
    int k =1;
    while(m>0&&k<=m)
    {
        cin>>n;
        for(int i = 0 ; i < n; i++)
        {
            cin>>arr[i].start>>arr[i].finish;
        }
        sort(arr,arr+n,cmp);
        int cnt = 1;
        int cur = arr[0].finish;
        for(int i = 1; i<n; i++)
        {
            if(arr[i].start>cur)
            {
                cnt = cnt +1;
                cur = arr[i].finish;
            }
        }
        cout << cnt << endl;
        k+=1;
    }


}
