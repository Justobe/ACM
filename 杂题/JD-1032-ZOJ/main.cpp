#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    while(cin>>str&&str!="E")
    {
        int z_cpcty = 0;
        int o_cpcty = 0;
        int j_cpcty = 0;
        for(int i = 0 ; i<str.length();i++)
        {
            if(str[i] == 'Z')
            {
                z_cpcty++;
            }
            if(str[i] == 'O')
            {
                o_cpcty++;
            }
            if(str[i] == 'J')
            {
                j_cpcty++;
            }
        }
        int cnt = 0;
        for(int i = 0 ; i <str.length();i++)
        {
            if(cnt == 0)
            {
                if(z_cpcty>0)
                {
                    cout<<"Z";
                    cnt = 1;
                    z_cpcty--;
                }
                else if(o_cpcty>0)
                {
                    cout<<"O";
                    cnt=2;
                    o_cpcty--;
                }
                else if(j_cpcty>0)
                {
                    cout<<"J";
                    cnt=0;
                    j_cpcty--;
                }
            }
            else if(cnt == 1)
            {
                if(o_cpcty>0)
                {
                    cout<<"O";
                    cnt=2;
                    o_cpcty--;
                }
                else if(j_cpcty>0)
                {
                    cout<<"J";
                    cnt=0;
                    j_cpcty--;
                }
                else if(z_cpcty>0)
                {
                    cout<<"Z";
                    cnt=1;
                    z_cpcty--;
                }
            }
            else if(cnt == 2)
            {
                if(j_cpcty>0)
                {
                    cout<<"J";
                    cnt=0;
                    j_cpcty--;
                }
                else if(z_cpcty>0)
                {
                    cout<<"Z";
                    cnt=1;
                    z_cpcty--;
                }
                else if(o_cpcty>0)
                {
                    cout<<"O";
                    cnt=2;
                    o_cpcty--;
                }
            }
        }
        cout<<endl;
    }
}
