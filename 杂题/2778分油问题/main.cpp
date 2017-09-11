#include <iostream>
#include <set>
#include <stack>
using namespace std;
int x,y,z,targ;
set<int>myset;
stack<int>mystack;
int a[4];
int b[4];
int c[4];
int main()
{
    while(cin>>a[1]>>a[2]>>a[3]>>targ&&a[1]&&a[2]&&a[3]&&targ)
    {
        myset.clear();
        while(!mystack.empty())
        {
            mystack.pop();
        }
        int tmp = a[1]*10000;
        //cout<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<endl;
        mystack.push(tmp);
        myset.insert(tmp);
        bool flag = false;
        while(!mystack.empty())
        {
            int tmp1 = mystack.top();
            mystack.pop();
            b[1] = tmp1/10000;
            b[2] = tmp1/100 - b[1]*100;
            b[3] = tmp1 - b[1]*10000 - b[2]*100;
            //cout<<b[1]<<" "<<b[2]<<" "<<b[3]<<" "<<endl;
            if(b[1] == targ||b[2]==targ||b[3]==targ)
            {
                flag = true;
                cout<<b[1]<<" "<<b[2]<<" "<<b[3]<<" "<<endl;
                break;
            }
            for(int i = 1;i<=3;i++)
            {
                for(int j = 1;j<=3;j++)
                {
                    c[1] = b[1];
                    c[2] = b[2];
                    c[3] = b[3];
                    if(i!=j&&c[i]>0)
                    {
                        if(a[j]>=(c[i]+c[j]))
                        {
                            c[j] = c[j]+c[i];
                            c[i] = 0;
                        }
                        else
                        {
                            c[i] = c[i] - (a[j]-c[j]);
                            c[j] = a[j];
                        }
                        int tmp2 = c[1]*10000+c[2]*100+c[3];
                       // cout<<tmp2<<endl;
                        if(myset.find(tmp2) == myset.end())
                        {
                            //cout<<i<<"->"<<j<<endl;
                           // cout<<tmp2<<endl;
                            myset.insert(tmp2);
                            mystack.push(tmp2);
                        }
                    }
                }
            }
        }
        if(flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}
