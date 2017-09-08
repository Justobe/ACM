#include <iostream>
#include <math.h>
using namespace std;
void isPrime(int num)
{
    bool flag = true;
    for(int i = 2;i<=sqrt(num);i++)
    {
        if(num%i==0)
        {
            flag = false;
            break;
        }
    }
    if(flag)
        cout<<num<<endl;
}
void printPrime(int year)
{
    for(int i = 1;i<=12;i++)
    {
        int num;
        if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)
        {
            for(int j =1;j<=31;j++)
            {
                num = year*10000 + i*100+j;
                isPrime(num);
            }
        }
        else if(i == 4||i==6||i==9||i==11)
        {
            for(int j =1;j<=30;j++)
            {
                num = year*10000 + i*100+j;
                isPrime(num);
            }
        }
        else
        {
            if(year == 1988)
            {
                for(int j =1; j<=29; j++)
                {
                    num = year*10000 + i*100+j;
                    isPrime(num);
                }
            }

            else
            {
                for(int j =1; j<=28; j++)
                {
                    num = year*10000 + i*100+j;
                    isPrime(num);
                }
            }
        }

    }
}
int main()
{
    printPrime(1988);
    printPrime(1989);
    return 0;
}
