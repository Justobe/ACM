#include <iostream>

using namespace std;

int main()
{
    int matrix[100][100];
    int n,e;
    cout<<"������ͼ�Ķ������ͱ����������0��ʼ����"<<endl;
    cin>>n>>e;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
                matrix[i][j] = 0;
            else
                matrix[i][j] = -1;
        }
    }

    for(int k=0;k<e;k++)
    {
        int from,to;
        cout<<"�������"<<k<<"���ߣ�"<<endl;
        cin>>from>>to;
        matrix[from][to] = 1;
        matrix[to][from] = 1;
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
           cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }


}
