#include <iostream>
#include<queue>
using namespace std;

int main()
{
    int arr[1002];
    int b[1002];
    int n;
    while(cin>>n)
    {
        priority_queue<int, vector<int>, greater<int> > ht;
        for(int i = 0 ; i <n; i++)
        {
            cin>>arr[i];
            ht.push(arr[i]);
        }
        int sum = 0;
        while(ht.size()>1)
        {
            int a = ht.top();
            ht.pop();
            int b = ht.top();
            ht.pop();
            sum = sum + a + b;
            ht.push(a+b);
        }
        cout<<sum<<endl;
    }
    return 0;

}
