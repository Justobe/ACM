#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(const int &a, const int &b)
{
    return a < b ? true:false;
}
int main()
{
    string str;
    int s;
    cin>>str>>s;
    int arr[250];
    int len = str.length();
    int resnum = len -s;
    for(int i = 0 ; i<len;i++)
    {
        int res = str[i] - 48;
        arr[i] = res;
    }
    int cur = 0;
    for(int i =0;i<s;i++)
    {
        bool flag = false;
        for(int j = 0;j<len - i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                cur = j;
                flag = true;
                break;
            }
        }
        if(flag)
        {
            for(int k = cur;k<len-i-1;k++)
            {
                arr[k] = arr[k+1];
            }
        }
    }
    for(int i = 0 ; i < len-s;i++)
    {
        cout<<arr[i];
    }
    cout<<endl;
    return 0;

}
