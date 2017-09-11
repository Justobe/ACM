#include <iostream>
#include <queue>
#include <set>
#include <string>
using namespace std;
int N;
set<string>myset;
deque<string>strdeque;
deque<int>cntdeque;
bool has2012(string str)
{
    for(int i = 0;i<=str.length()-4;i++)
    {
        if(str.substr(i,4) == "2012")
            return true;
    }
    return false;
}
int main()
{

    while(cin>>N&&N)
    {
        string str;
        cin>>str;
        if(N<4)
            cout<<"-1"<<endl;
        else
        {
            myset.clear();
            strdeque.clear();
            cntdeque.clear();
            strdeque.push_back(str);
            cntdeque.push_back(0);
            bool flag = false;
            while(!strdeque.empty()&&!cntdeque.empty())
            {
                int cnt = cntdeque.front();
                cntdeque.pop_front();
                string tmp = strdeque.front();
                strdeque.pop_front();
                //cout<<tmp<<" "<<cnt<<endl;
                if(has2012(tmp))
                {
                    cout<<cnt<<endl;
                    flag = true;
                    break;
                }
                else
                {
                    for(int i = 0;i<tmp.length()-1;i++)
                    {
                        string tmp2 = tmp;
                        swap(tmp2[i],tmp2[i+1]);
                        //cout<<tmp2<<endl;
                        if(myset.find(tmp2)==myset.end())
                        {
                            //cout<<"insert:"<<tmp2<<endl;
                            myset.insert(tmp2);
                            strdeque.push_back(tmp2);
                            cntdeque.push_back(cnt+1);
                        }
                    }
                }

            }
            if(flag == false)
            {
                cout<<-1<<endl;
            }

        }

    }

}
