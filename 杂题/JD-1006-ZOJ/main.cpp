#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    while(cin>>str)
    {

        int zindex1 = str.find('z');
        int zindex2 = str.find_last_of('z');
        int jindex1 = str.find('j');
        int jindex2 = str.find_last_of('j');
        if(zindex1 != zindex2||zindex1==-1)
            cout<<"Wrong Answer"<<endl;
        else if(jindex1!=jindex2||jindex1==-1)
            cout<<"Wrong Answer"<<endl;
        else
        {
            int s = 0;
            int e = str.length() - 1;
            int acnt = 0,bcnt = 0,ccnt = 0;
            for(int i = s; i<zindex1; i++)
            {
                if(str[i]=='o')
                    acnt+=1;
            }
            for(int i =zindex1+1; i<jindex1; i++)
            {
                if(str[i]=='o')
                    bcnt+=1;
            }
            for(int i = jindex1+1; i<=e; i++)
            {
                if(str[i]=='o')
                    ccnt+=1;
            }
            if(acnt*bcnt == ccnt&&bcnt>=1)
                cout<<"Accepted"<<endl;
            else
                cout<<"Wrong Answer"<<endl;
        }
    }
    return 0;

}
