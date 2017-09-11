#include <iostream>
#include <stack>
using namespace std;
//wa
int main()
{
    int A;
    int B;
    long long int res;
    int m;
    while(cin>>m&&m)
    {
        cin>>A>>B;
        res = A+B;
        if(A==0&&B==0)
        {
            cout<<0<<endl;
        }
        else
        {
            stack<int>answer;
            while(!answer.empty())
            {
                answer.pop();
            }
            long long int left = res;
            int rest = 0;
            while(left!=0)
            {
                rest = left%m;
                left = left/m;
                //cout<<left<<" "<<rest<<endl;
                answer.push(rest);
            }
            while(!answer.empty())
            {
                cout<<answer.top();
                answer.pop();
            }
            cout<<endl;
        }
    }
    return 0;
}
