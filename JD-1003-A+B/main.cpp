#include <iostream>
#include <math.h>
using namespace std;
int getLen(string num)
{
    int cnt = 0;
    for(int i = 0 ; i <num.length();i++)
    {
        if(num[i]>='0'&&num[i]<='9')
        {
            cnt+=1;
        }
    }
    return cnt;

}
long mypow(int a,int b)
{
    long res = 1;
    for(int i = 0 ; i <b;i++)
    {
        res = res*a;
    }
    return res;
}
long getNumber(string num,int cnt)
{
    long res = 0;
    cnt = cnt - 1;
    for(int i = 0 ; i <num.length();i++)
    {
        if(num[i]>='0'&&num[i]<='9')
        {

            int a = num[i] - '0';
            long add = mypow(10,cnt);
            res = res + a*add;
            cnt--;
        }
    }
    if(num[0]=='-')
        res = 0 - res;
    return res;
}
int main()
{
    string A,B;
    while(cin>>A>>B)
    {
        int len1 = A.length();
        int len2 = B.length();
        int cnt1 = getLen(A);
        int cnt2 = getLen(B);
        long num1 = getNumber(A,cnt1);
        long num2 = getNumber(B,cnt2);
        long res = num1 + num2;
        cout<<res<<endl;
    }
    return 0;
}
