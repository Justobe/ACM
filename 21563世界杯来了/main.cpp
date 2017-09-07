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
    while(cin>>n&&n)
    {
        for(int i = 0 ; i < n; i++)
        {
            cin>>arr[i].start>>arr[i].finish;
        }
        sort(arr,arr+n,cmp);
        int cnt = 1;
        int cur = 0;
        for(int i = 1; i<n; i++)
        {
            if(arr[cur].finish <= arr[i].start)
            {
                cnt = cnt +1;
                cur = i;
            }
        }
        cout << cnt << endl;
    }


}
