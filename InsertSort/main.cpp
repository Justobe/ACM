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
        //��������
        for(int i = 0 ; i < n ; i ++)
        {
            cin>>arr[i];
        }
        int j,k,l;
        //�㷨ִ�� k-1 ��
        for(k = 1; k<n; k++)
        {
            //�Ӻ���ǰ�ҵ�һ����arr[k]С����
            for(j = k-1; j>=0; j--)
            {
                if(arr[k]>=arr[j])
                {
                    break;
                }
            }
            //���j = k-1 ����Ҫ����
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
            //��� arr[k] �� arr[k-1]������֮ǰ��������ģ����Բ��ò���
            if(arr[k]<arr[k-1])
            {
                int temp = arr[k];
                //�ȽϺ��ֱ���ƶ�
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
