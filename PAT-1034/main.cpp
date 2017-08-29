// ConsoleApplication2.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <cstdlib>
#include <string>
#include <map>
using namespace std;
typedef struct Person {
	int number;
	Person *next;
}Person;
Person pList[27];
int weight[27];
int flag[27];
int head;
int cnt;
int ttlWeight;
map<int, int>gang;
void dfs(int s)
{
    cnt = cnt + 1;
    ttlWeight = ttlWeight + weight[s];
    if (weight[s] > weight[head])
    {
        head = s;
    }
    flag[s] = 1;
    if (pList[s].next != NULL)
    {
        Person *tmp = pList[s].next;
        while (tmp != NULL)
        {
            int num = tmp->number;
            if (flag[num] == 0)
            {
                dfs(num);
            }
            tmp = tmp->next;
        }
    }
}
int getDigit(string name)
{
    return (name[0] - 'A' + 1);
}

string getName(int name)
{
    char c = name - 1 + 'A';
    char arr[4];
    arr[0] = c;
    arr[1] = c;
    arr[2] = c;
    arr[3] = '\0';
    string str = arr;
    return str;
}

void init()
{
    for (int i = 0; i<27; i++)
    {
        pList[i].number = i;
        pList[i].next = NULL;
    }
}
Person* getNewPerson(int number, string name)
{
    Person *p = (Person*)malloc(sizeof(Person*));
    //p->name = name;
    p->number = number;
    p->next = NULL;
    return p;
}

int main()
{
    int N, K;
    while(cin >> N >> K)
    {
        gang.erase(gang.begin(),gang.end());
        weight[27] = { 0 };
        flag[27]={0};
        init();
        for (int i = 0; i < N; i++)
        {
            string n1, n2;
            int w;
            cin >> n1 >> n2 >> w;
            int num1 = getDigit(n1);
            int num2 = getDigit(n2);
            Person *p1 = getNewPerson(num2,n2);
            weight[num1] += w;
            weight[num2] += w;
            p1->next = pList[num1].next;
            pList[num1].next = p1;
            p1 = NULL;
        }

        for (int i = 0; i < 27; i++)
        {
            if (flag[i] == 0 && pList[i].next != NULL)
            {
                head = i;
                cnt = 0;
                ttlWeight = 0;
                dfs(i);
                if(cnt>2&&ttlWeight>2*K)
                    gang.insert(pair<int, int>(head,cnt));
            }
        }
        map<int, int>::iterator it;
        cout<<gang.size()<<endl;
        for (it = gang.begin(); it != gang.end(); it++)
        {
            int gnum = it->first;
            cout << getName(gnum) << " " << it->second << endl;
        }

    }
    return 0;

	/*for (int i = 0; i < 27; i++)
	{
		if (pList[i].next != NULL)
		{
			cout <<getName(i) << "-> ";
			Person *tmp = pList[i].next;
			while (tmp != NULL)
			{
				int num = tmp->number;
				cout <<getName(num)<< " ";
				tmp = tmp->next;
			}
			cout << endl;
		}
	}*/

}

