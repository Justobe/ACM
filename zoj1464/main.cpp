#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

int main()
{
    char str[90];
    while(scanf("%s",str)!=EOF)
    {
        int length = 0;
        while(str[length]!='\0')
        {
            length++;
        }
        int N = length;
        int n1,n2,n3;
        for(n2 = 3; n2<=N; n2++)
        {
            int temp = N-n2+2;
            if(temp%2!=0)
                continue;
            n1 = n3 = temp/2;
            if(n1<=n2)
                break;
        }
        for(int i = 0; i< n1-1; i++)
        {
            printf("%c",str[i]);
            for(int j =0; j<n2-2; j++)
            {
                printf(" ");
            }
            printf("%c\n",str[N - 1 - i]);
        }

        for(int k = 0; k<n2; k++)
        {
            printf("%c",str[n1-1+k]);
        }
        printf("\n");
    }
    return 0;
}
