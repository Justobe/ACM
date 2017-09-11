#include <iostream>

using namespace std;

int main()
{
    int x,y;
    while(cin>>x>>y)
    {
        if(x == 0 && y == 0)
            break;
        int xmin,xmax;
        int ymin,ymax;
        xmin = xmax = x;
        ymin = ymax = y;
        while(cin>>x>>y)
        {
            if(x == 0 && y == 0)
                break;
            if(x>xmax)
                xmax = x;
            if(x<xmin)
                xmin = x;
            if(y>ymax)
                ymax = y;
            if(y<ymin)
                ymin = y;
        }
        cout<< xmin <<" "<<ymin<<" "<<xmax<<" "<<ymax<<endl;
    }
    return 0;
}
