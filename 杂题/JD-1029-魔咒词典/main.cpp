#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;
map<string,string>dic;
string getZhouYu(string zy)
{
    char arr[25];
    int len = zy.length();
    for(int i = 1; i<=len-2; i++)
    {
        arr[i-1] = zy[i];
    }
    arr[len-2] = '\0';
    string res = arr;
    return res;
}
string getType(string str)
{
    if(str[0] == '[')
        return "zy";
    else
        return "gn";
}
string findZhouYu(string gn)
{
    map<string,string>::iterator it;
    for(it = dic.begin();it!=dic.end();it++)
    {
        if(it->second == gn)
        {
            return it->first;
        }
    }
    return "what?";
}
int main()
{

    string zy,gn;
    string first;
    while(cin>>first&&first!="@END@")
    {
        if(first[first.length()-1]!=']')
        {
            string second;
            cin>>second;
            zy = first +" "+ second;
        }
        else
        {
            zy = first;
        }
        getchar();
        getline(cin,gn);
        string nzy = getZhouYu(zy);
        dic.insert(pair<string,string>(nzy,gn));
    }

    /*map<string,string>::iterator ptr;
    for(ptr = dic.begin();ptr!=dic.end();ptr++)
    {
       cout<<ptr->first<<" "<<ptr->second<<endl;
    }*/
    int qnum;
    cin>>qnum;
    getchar();
    for(int i = 0 ; i <qnum; i++)
    {
        string tmp;
        getline(cin,tmp);
        //cout<<tmp<<endl;
        string mytype = getType(tmp);
        if(mytype == "zy")
        {
            string a = getZhouYu(tmp);
            if(dic.count(a) == 0)
                cout<<"what?"<<endl;
            else
                cout<<dic[a]<<endl;
        }
        else
        {
            cout<<findZhouYu(tmp)<<endl;
        }
    }
    return 0;

}
