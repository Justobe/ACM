/*#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char tmp[8];
char ans[8];
bool visited[8];
int len;
void getPL(int i)
{
    if(i == len)
    {
        ans[len] = '\0';
        //cout<<ans<<endl;
        printf("%s\n",ans);
    }
    else
    {
        for(int j = 0 ; j < len;j++)
        {
            if(visited[j] == false)
            {
                visited[j] = true;
                ans[i] = tmp[j];
                getPL(i+1);
                visited[j] = false;
            }
        }
    }

}
int main()
{
    char str[8];
    while(scanf("%s",str)!=EOF)
    {
        len = strlen(str);
        for(int i = 0 ; i <len; i++)
        {
            tmp[i] = str[i];
            visited[i] = false;
        }
        tmp[len] = '\0';
        getPL(0);
        printf("\n");
    }
}*/

