#include <iostream>
#include <set>
#define MAX 9999
#define pnum 28
using namespace std;
int arr[pnum][pnum];
int getId(char c)
{
    return c - 'A';
}
bool isPerson(char c)
{
    if(c>='A'&&c<='Z')
        return true;
    else
        return false;
}
void print(char l,char r)
{
    int ln = getId(l);
    int rn = getId(r);
    int dis_lr = arr[ln][rn];
    int dis_rl = arr[rn][ln];
    if(dis_lr>0&&dis_lr!=MAX)
    {
        if(dis_lr == 1)
            cout<<"child"<<endl;
        else
        {
            int num = dis_lr - 2;
            while(num>0)
            {
                num--;
                cout<<"great-";
            }
            cout<<"grandchild"<<endl;
        }
    }
    else if(dis_rl>0&&dis_rl!=MAX)
    {
        if(dis_rl == 1)
            cout<<"parent"<<endl;
        else
        {
            int num = dis_rl - 2;
            while(num>0)
            {
                num--;
                cout<<"great-";
            }
            cout<<"grandparent"<<endl;
        }
    }
    else
    {
        cout<<"-"<<endl;
    }
}
int main()
{
    int n,m;

    while(cin>>n>>m&&n>0&&m>0)
    {
        for(int i = 0; i <pnum; i++)
        {
            for(int j = 0; j<pnum; j++)
            {
                if(i!=j)
                    arr[i][j] = MAX;
                else
                    arr[i][j] = 0;
            }
        }
        set<int>myset;
        for(int i = 0; i<n; i++)
        {
            char child;
            char father;
            char mother;
            string str;
            cin>>str;
            child = str[0];
            father=str[1];
            mother = str[2];
            myset.insert(getId(child));
            int cid = getId(child);
            if(isPerson(father))
            {
                myset.insert(getId(father));
                int fid = getId(father);
                arr[cid][fid] = 1;
            }
            if(isPerson(mother))
            {
                myset.insert(getId(mother));
                int mid = getId(mother);
                arr[cid][mid] = 1;
            }
        }
        int cnt = myset.size();
        set<int>:: iterator k,i,j;
        for(k = myset.begin(); k!=myset.end(); k++)
        {
            for(i = myset.begin(); i!=myset.end(); i++)
            {
                for(j = myset.begin(); j!=myset.end(); j++)
                {
                    int num_k = *k;
                    int num_i = *i;
                    int num_j = *j;
                    if(arr[num_i][num_j]>arr[num_i][num_k]+arr[num_k][num_j])
                    {
                        arr[num_i][num_j] = arr[num_i][num_k]+arr[num_k][num_j];
                    }
                }
            }
        }
        for(int i = 0; i<m; i++)
        {
            string str;
            cin>>str;
            char l = str[0],r = str[1];
            print(l,r);
        }
    }
    return 0;
}
