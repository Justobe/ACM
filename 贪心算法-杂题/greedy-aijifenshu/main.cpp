#include <iostream>

using namespace std;

int main()
{
    int cnt = 0;
    int a = 2,b = 45;
    for(int i =1;i<45;i++)
    {
        if(a*i-b>0)
        {
            int top = a*i-b;
            int down = b*i;
            if(down%top == 0)
            {
                cnt = cnt + 1;
            }
        }
    }
    cout<<cnt<<endl;
}
