#include<iostream>
#include<cmath>
#include<math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

typedef struct interval
{
    double l;
    double r;

};
bool cmp(const interval a,const interval b)
{
    if(a.r!=b.r)
    {
        return a.r < b.r;
    }
    else
        return a.l>b.l;
}
interval in[1020];
int n;
double d;

int main()
{
    int t = 0;
    while(cin>>n>>d&&n&&d)
    {
        t++;
        bool flag = true;
        for(int i = 0 ; i <n; i++)
        {
            double x;
            double y;
            cin>>x>>y;
            if(y>d)
            {
                flag = false;
            }
            if(flag)
            {
                in[i].l = x - sqrt(d*d-y*y);
                in[i].r = x + sqrt(d*d-y*y);
            }
        }
        if(flag == false)
        {
            cout<<"Case "<<t<<": "<<-1<<endl;
        }
        else
        {

            sort(in,in+n,cmp);
            /*for(int i = 0 ; i<n;i++)
            {
                cout<<in[i].l<<" "<<in[i].r<<endl;
            }*/
            double cur = in[0].r;
            int cnt = 1;
            for(int i = 1; i<n; i++)
            {
                if(in[i].l>cur)
                {
                    cur = in[i].r;
                    cnt++;
                }
            }
            cout<<"Case "<<t<<": "<<cnt<<endl;
        }
    }
    return 0;
}
