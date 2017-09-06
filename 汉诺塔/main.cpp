#include <iostream>

using namespace std;
int total = 1;
void hanoi(char src,char trgt,char left,int cnt)
{
    if(cnt == 1)
    {
        cout<<total<<" :from "<<src<<"-->"<<trgt<<endl;
        total++;
        return;
    }
    else
    {
        hanoi(src,left,trgt,cnt - 1);
        hanoi(src,trgt,left,1);
        hanoi(left,trgt,src,cnt -1);
    }
}
int main()
{
    int cnt;
    cin>>cnt;
    hanoi('a','c','b',cnt);
    return 0;
}
