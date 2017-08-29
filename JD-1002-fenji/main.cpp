#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
double getClose(double G1,double G2,double G3)
{
    if(fabs(G1-G3)>fabs(G2-G3))
    {
        return G2;
    }
    else
    {
        return G1;
    }
}
double getMax(double G1,double G2,double G3)
{
    if(G1>G2&&G1>G3)
        return G1;
    else if(G2>G1&&G2>G3)
        return G2;
    else
        return G3;
}
int main()
{
    double P,T,G1,G2,G3,GJ;
    while(cin>>P>>T>>G1>>G2>>G3>>GJ)
    {

        double diff = fabs(G1-G2);
        double diff1 = fabs(G1-G3);
        double diff2 = fabs(G2-G3);
        if(diff>T)
        {
            if(diff1>T&&diff2>T)
            {
                cout<<fixed<<setprecision(1)<<GJ<<endl;
            }
            else if (diff1>T||diff2>T)
            {
                double G = getClose(G1,G2,G3);
                cout<<fixed<<setprecision(1)<<(G+G3)/2<<endl;
            }
            else
            {
                double grade = getMax(G1,G2,G3);
                cout<<fixed<<setprecision(1)<<grade<<endl;
            }
        }
        else
        {
            cout<<fixed<<setprecision(1)<<(G1+G2)/2<<endl;
        }
    }
    return 0;

}
