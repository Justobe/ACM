#include <iostream>
#include <iomanip>
using namespace std;
int N;
int arr[102];
int main()
{
    cin>>N;
    for(int i = 0 ; i <N;i++)
    {
        cin>>arr[i];
    }
    double A = 100,B = 0;
    int lchange = -1;
    for(int i = 0;i<N-1;i++)
    {
        //cout<<A<<" "<<B<<endl;
        if(A == 0.0&&arr[i]<arr[i+1])
        {
            //cout<<"m to d"<<endl;
            A = (B/arr[i])*100;
            B = 0;
            lchange = i;
        }
        else if(B == 0.0&&arr[i]>arr[i+1])
        {
            //cout<<"d to m"<<endl;
            B = (A/100)*arr[i];
            A = 0;
            lchange = i;
        }
        //cout<<A<<" "<<B<<endl;
    }
    if(A == 0)
    {
        if(lchange == N-1)
        {
            A = (B/arr[lchange])*100;
        }
        else
        {
            int m = arr[lchange];
            int mindex = lchange;
            for(int i = lchange+1;i<N;i++)
            {
                if(arr[i]<m)
                {
                    mindex = i;
                }
            }
            A = (B/arr[mindex])*100;
        }
    }
    cout<<fixed<<setprecision(2)<<A<<endl;
}
