#include <iostream>
#include <vector>
#include <algorithm>
#define N 40000
#define M 100
#define K 5
using namespace std;
typedef struct Application
{
    int GE;
    int GI;
    int fscore;
    int choice[K+2];
    int number;
    int selection;
};
Application aList[N+2];
typedef struct School
{
    int number;
    int capacity;
    int cnt;
    int aid[N+2];
};
School school[M+2];
bool cmp(const Application&a,const Application&b)
{
    if(a.fscore>b.fscore)
    {
        return a.fscore>b.fscore;
    }
    else if(a.fscore == b.fscore && a.GE>b.GE)
    {
        return a.GE>b.GE;
    }
    else if (a.fscore == b.fscore && a.GE == b.GE)
    {
        return a.number < b.number;
    }
    return false;
}
int main()
{
    int anum;
    int snum;
    int cnum;
    while(cin>>anum>>snum>>cnum)
    {
        for(int i = 0 ; i <snum; i++)
        {
            cin>>school[i].capacity;
            school[i].cnt = 0;
            //school[i].number = i;
        }
        for(int j = 0 ; j<anum; j++)
        {
            cin>>aList[j].GE>>aList[j].GI;
            aList[j].fscore = aList[j].GE + aList[j].GI;
            for(int i = 0 ; i<cnum; i++)
            {
                cin>>aList[j].choice[i];
            }
            aList[j].number = j;
            aList[j].selection = -1;
        }
        sort(aList,aList+anum,cmp);


        for(int i = 0; i<anum; i++)
        {
            for(int j = 0; j<cnum; j++)
            {
                int sid = aList[i].choice[j];
                if(school[sid].capacity>0)
                {
                    aList[i].selection = sid;
                    school[sid].capacity--;
                    school[sid].aid[school[sid].cnt] = i;
                    school[sid].cnt++;
                    break;
                }
                else
                {
                    if(aList[i].selection == -1)
                    {
                        int sid = aList[i].choice[j];
                        int cnt = school[sid].cnt;
                        if(cnt>0)
                        {
                            int lastAid = school[sid].aid[cnt-1];
                            if(aList[i].fscore == aList[lastAid].fscore&&aList[i].GE == aList[lastAid].GE)
                            {
                                school[sid].aid[school[sid].cnt] = i;
                                school[sid].cnt++;
                                aList[i].selection = sid;
                                break;
                            }
                        }

                    }
                }
            }

        }

        for(int i = 0 ; i <snum; i++)
        {
            for(int j = 0 ; j <school[i].cnt; j++)
            {
                int arank = school[i].aid[j];
                school[i].aid[j] = aList[arank].number;
            }
            if(school[i].cnt>1)
            {
                sort(school[i].aid,school[i].aid+school[i].cnt);
            }
        }

        for(int i = 0; i<snum; i++)
        {
            if(school[i].cnt == 0)
                cout<<endl;
            else
            {
                int cnt = school[i].cnt;
                for(int j = 0 ; j <cnt; j++)
                {
                    if(j!=cnt-1)
                    {
                        cout<<school[i].aid[j]<<" ";
                    }
                    else
                    {
                        cout<<school[i].aid[j];
                    }
                }
                cout<<endl;
            }

        }
    }

    return 0;

}
