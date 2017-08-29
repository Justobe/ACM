#include <iostream>
#include <cstdlib>
using namespace std;
typedef struct TreeNode {
	int key;
	TreeNode *leftChild;
	TreeNode *rightChild;
}TreeNode, *PTree;
void insertNode(PTree *T, int val) {
	if (*T == NULL)
	{
		*T = (PTree)malloc(sizeof(TreeNode));
		(*T)->key = val;
		(*T)->leftChild = NULL;
		(*T)->rightChild = NULL;
	}
	else
	{
		int key = (*T)->key;
		if (val<key)
		{
			insertNode(&(*T)->leftChild, val);
		}
		else
		{
			insertNode(&(*T)->rightChild, val);
		}
		//else
           // return;
	}
}
bool equalTree(PTree T1,PTree T2)
{
    if(T1 == NULL&&T2 == NULL)
        return true;
    else if(T1!=NULL&&T2!=NULL&&
            T1->key == T2->key&&
            equalTree(T1->leftChild,T2->leftChild)&&
            equalTree(T1->rightChild,T2->rightChild))
        return true;
    else
        return false;
}
int arr1[12];
int arr2[12];
void getNumber(int arr[],string n)
{
    int len = n.length();
    for(int i = 0 ; i <len;i++)
    {
        arr[i] = n[i] - '0';
    }
}
int main()
{
	int t;
	while(cin>>t&&t>0&&t<21)
    {
        string n1;
        cin>>n1;
        //cin>>n1>>n2;
        PTree P1 = NULL;
        getNumber(arr1,n1);
        //getNumber(arr2,n2);
        for(int i = 0; i<n1.length(); i++)
        {
            insertNode(&P1,arr1[i]);
        }
        while(t--)
        {
            string n2;
            cin>>n2;
            getNumber(arr2,n2);
            PTree P2 = NULL;
            for(int i = 0; i<n2.length(); i++)
            {
                insertNode(&P2,arr2[i]);
            }
            if(equalTree(P1,P2))
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }

    }
    return 0;
}
