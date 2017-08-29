#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

int main()
{
    int n;
    int arr [1000] = {0};
    while(cin >> n)
    {
        //读入数组
        for(int i = 0 ; i < n ; i ++)
        {
            cin>>arr[i];
        }
        int j,k,l;
        //算法执行 k-1 次
        for(k = 1; k<n; k++)
        {
            //从后往前找第一个比arr[k]小的数
            for(j = k-1; j>=0; j--)
            {
                if(arr[k]>=arr[j])
                {
                    break;
                }
            }
            //如果j = k-1 不需要交换
            if(j!=k-1)
            {
                int temp = arr[k];
                for(l = k-1; l>j; l--)
                {
                    arr[l+1] = arr[l];
                }
                arr[j+1] = temp;
            }
        }
        /*for(k = 1; k < n ; k ++)
        {
            //如果 arr[k] 比 arr[k-1]大，由于之前都是有序的，所以不用插入
            if(arr[k]<arr[k-1])
            {
                int temp = arr[k];
                //比较后的直接移动
                for(j = k - 1;j>=0 && arr[j]>temp;j--)
                {
                   arr[j+1] = arr[j];
                }
                arr[j+1] = temp;
            }
        }*/

        for(int i = 0 ; i < n ; i ++)
        {
            cout<<arr[i]<<" ";
        }
    }
    return 0;
}
