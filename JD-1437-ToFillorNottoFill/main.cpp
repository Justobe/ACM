#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

int main()
{
    double tank;
    double money;
    double leftoil;
    double dis,speed;
    int nextloc,N;
    while(cin>>tank>>dis>>speed>>N)
    {
        money = 0;
        leftoil = 0;
        double a[30002];
        int exists[300002] = {0};
        memset(a,-1.0,sizeof(double));
        bool flag = false;
        for(int i = 0 ; i <N; i++)
        {
            double price;
            int location;
            cin>>price>>location;
            a[location] = price;
            exists[location] = 1;
            if(location == 0)
                flag = true;
        }
        if(flag!=true)
        {
            cout<<"The maximum travel distance = 0.00"<<endl;
        }
        else
        {
            double mile = tank*speed;
            nextloc = 0;
            while(true)
            {
                double minest = 9999999;
                int mindex = -1;
                int firstmin = -1;
                for(int i = nextloc+1; i<=nextloc+mile&&i<dis; i++)
                {
                    if(exists[i]==1&&a[i]<=a[nextloc])
                    {
                        firstmin = i;
                        break;
                    }
                    if(exists[i]==1&&a[i]<=minest)
                    {
                        mindex = i;
                        minest = a[i];
                    }

                }
                if(firstmin != -1)
                {

                    double curprice = a[nextloc];
                    int btwndis = firstmin - nextloc;
                    double cost = btwndis/speed;
                    if(leftoil > cost)
                    {
                        leftoil = leftoil - cost;
                    }
                    else
                    {
                        money = money + (cost - leftoil)*curprice;
                        nextloc = firstmin;
                        leftoil = 0;
                    }
                }
                else if(nextloc + mile >= dis)
                {
                    double curprice = a[nextloc];
                    int tmpdis = dis - nextloc;
                    double cost = tmpdis/speed;
                    money = money +(cost - leftoil)*curprice;
                    cout<<fixed<<setprecision(2)<<money<<endl;
                    break;
                }
                else if(mindex!=-1)
                {
                    double curprice = a[nextloc];
                    int btwndis = mindex - nextloc;
                    money = money + (tank - leftoil)*curprice;
                    nextloc = mindex;
                    leftoil = tank - (btwndis/speed);
                }
                else
                {
                    cout<<"The maximum travel distance = "<<fixed<<setprecision(2)<<double(nextloc + mile)<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}
