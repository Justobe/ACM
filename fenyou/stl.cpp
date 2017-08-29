
#include <iostream>
#include <deque>
#include <list>
using namespace std;
void fenyou(int content[], int targ);
typedef struct myStatNode {
	string stat;
	int c[4];
	int step;
	int from;
};
void fenyou(int content[3], int targ)
{
	deque<myStatNode> nodeList;
	myStatNode startNode;
	startNode.stat = "null"; startNode.c[1] = 80; startNode.c[2] = 0;
	startNode.c[3] = 0; startNode.step = 0; startNode.from = -1;
	nodeList.push_back(startNode);
	deque<myStatNode>::iterator iter = nodeList.begin();
	while (nodeList.back().c[1] != 40 && nodeList.back().c[2]!=40 && nodeList.back().c[3] != 40)
	{
		if (iter != nodeList.begin())
		{
			iter++;
		}

		myStatNode tempNode;
		string stat;
		for (int i = 1; i <= 3; i++)
		{
			if (iter->c[i] > 0)
			{
				for (int j = 1; j <= 3 && j != i; j++)
				{
					if (iter->c[j] < content[j])
					{
						if (iter->c[i] + iter->c[j] <= content[j])
						{

							tempNode.c[1] = iter->c[1];
							tempNode.c[2] = iter->c[2];
							tempNode.c[3] = iter->c[3];
							tempNode.c[i] = 0;
							tempNode.c[j] = iter->c[i] + iter->c[j];
						}
						else
						{
							tempNode.c[1] = iter->c[1];
							tempNode.c[2] = iter->c[2];
							tempNode.c[3] = iter->c[3];
							tempNode.c[i] = iter->c[i] - (content[j] - iter->c[j]);
							tempNode.c[j] = content[j];
						}
						bool flag = true;
						deque<myStatNode>::iterator iter2;
						for (iter2 = nodeList.begin(); iter2 !=nodeList.end(); iter2++)
						{
							if (iter2->c[1] == tempNode.c[1] && iter2->c[2] == tempNode.c[2]&& iter2->c[3] == tempNode.c[3])
							{
								flag = false;
								break;
							}
						}
						if (flag == true)
						{
							myStatNode newNode;
							newNode.c[1] = tempNode.c[1];
							newNode.c[2] = tempNode.c[2];
							newNode.c[3] = tempNode.c[3];
							newNode.step = iter->step + 1;
							newNode.from = iter - nodeList.begin();
							if (i == 1 && j == 2)
							{
								newNode.stat = "X->Y";
							}
							if (i == 1 && j == 3)
							{
								newNode.stat = "X->Z";
							}
							if (i == 2 && j == 1)
							{
								newNode.stat = "Y->X";
							}
							if (i == 2 && j == 3)
							{
								newNode.stat = "Y->Z";
							}
							if (i == 3 && j == 1)
							{
								newNode.stat = "Z->X";
							}
							if (i == 3 && j == 2)
							{
								newNode.stat = "Z->Y";
							}

						}
					}
				}
			}
		}

	}

	deque<myStatNode>::iterator iter3;
	for (iter3 = nodeList.begin(); iter3 != nodeList.end(); iter3++)
	{
		cout<< iter3->c[1] << " " << iter3->c[2] << " " << iter3->c[3] << " " << iter3->step << " " << iter3->from << endl;
	}
}
int main()
{
	int x = 80, y = 50, z = 30, targ = 40;
	int content[3] = { 80,50,30 };
	fenyou(content, targ);
}


