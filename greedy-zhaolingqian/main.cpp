#include <iostream>
#include <string>
using namespace std;

int main()
{
    int m;
    while(cin>>m&&m>0)
    {
        int arr[5] = {50,20,10,5,1};
        int res = m;
        int cnt = 0;
        string str = "";
        for(int i = 0; i<5; i++)
        {
            cnt = res/arr[i];
            if(cnt != 0)
            {
                res = res%arr[i];
                //str = str + arr[i] + "*" +cnt;
                if(res == 0)
                {
                    cout<<arr[i]<<"*"<<cnt<<endl;
                    break;
                }
                else
                    cout<<arr[i]<<"*"<<cnt<<"+";
            }
        }
    }
}
