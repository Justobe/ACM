#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct TreeNode
{
    char data;
    struct TreeNode *lchild, *rchild;
}TreeNode,*Tree;

void createTree(Tree *T)
{
    char mychar;
    cin>>mychar;
    if(mychar!='#')
    {
        *T = (Tree)malloc(sizeof(TreeNode));
        (*T)->data = mychar;
        createTree(&(*T)->lchild);
        createTree(&(*T)->rchild);

    }
    else
    {
        *T = NULL;
    }
}


void preOrderTraverse(Tree T)
{
    if(T==NULL)
    {
        return;
    }
    cout<<T->data;
    preOrderTraverse(T->lchild);
    preOrderTraverse(T->rchild);
}
void midOrderTraverse(Tree T)
{
    if(T==NULL)
    {
        return;
    }

    midOrderTraverse(T->lchild);
    cout<<T->data;
    midOrderTraverse(T->rchild);
}
void postOrderTraverse(Tree T)
{
    if(T==NULL)
    {
        return;
    }
    postOrderTraverse(T->lchild);
    postOrderTraverse(T->rchild);
    cout<<T->data;
}



int main()
{
    Tree T = NULL;
    createTree(&T);
    preOrderTraverse(T);
    cout<<endl;
    midOrderTraverse(T);
    cout<<endl;
    postOrderTraverse(T);
    return 0;
}
