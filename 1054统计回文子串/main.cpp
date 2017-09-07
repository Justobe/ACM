/*#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <string.h>
using namespace std;
char tmp[5010];
int main()
{
    char tmp[5010];
    while(scanf("%s",&tmp)!=EOF)
    {
        int len = strlen(tmp);
        int cnt = 0;
        for(int i = 0 ; i <len;i++)
        {
            for(int j = i;j<len;j++)
            {
                int mid = (j-i)/2;
                int left = i+mid;
                int right = j-mid;
                bool flag = true;
                while(left>=i&&right<=j)
                {
                    if(tmp[left]!=tmp[right])
                    {
                        flag = false;
                        break;
                    }
                    else
                    {
                        left--;
                        right++;
                    }
                }
                if(flag)
                {
                    //cout<<i<<" "<<j<<" "<<cnt<<endl;
                    cnt++;
                }

            }
        }
        cout<<cnt<<endl;
    }
}*/
#include<stdio.h>
#include<string.h>
char s[5007];
int main()
{
    while(scanf("%s",s)!=EOF)
    {
        int  len=strlen(s)-1,ans=0,l,r;
        for(int i=0;i<=len;++i,++ans)
        {
            for(l=i-1,r=i+1;l>=0&&r<=len&&s[l]==s[r];--l,++r,++ans)
            ;
            for(l=i,r=i+1;l>=0&&r<=len&&s[l]==s[r];--l,++r,++ans)
            ;
        }
        printf("%d\n",ans);
    }
    return 0;
}
