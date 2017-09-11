#include <iostream>

using namespace std;

int main()
{


    int M,N;// M rows N cols
    while(cin>>M&&M>0)
    {
        cin>>N;
        int matrix [11][11];
        int rows[11] = {0};
        int cols[11] = {0};
        for(int i = 0 ; i <11; i++)
        {
            for(int j =0; j<11; j++)
            {
                matrix[i][j] = 0;
            }
        }

        for(int i = 0; i<M; i++)
        {
            for(int j = 0; j<N; j++)
            {
                int x;
                cin>>x;
                matrix[i][j] = x;
            }
        }

        for(int i = 0; i<M; i++)
        {
            for(int j = 0; j<N; j++)
            {
                int y;
                cin>>y;
                matrix[i][j] += y;
                if(matrix[i][j] == 0)
                {
                    rows[i]++;
                    cols[j]++;
                }
            }
        }
        int cnt = 0;
        for(int i = 0 ; i <M; i++)
        {
            if(rows[i] == N)
                cnt = cnt + 1;
        }

        for(int j = 0 ; j <N; j++)
        {
            if(cols[j] == M)
                cnt = cnt + 1;
        }
        cout<<cnt<<endl;
    }
    return 0;


}
