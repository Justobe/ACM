#include <iostream>
#include <stdlib.h>
#include <stack>
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
   stack<Tree>mystack;
   while(!mystack.empty())
   {
       mystack.pop();
   }
   mystack.push(T);
   TreeNode *p;
   while(!mystack.empty())
   {
       p = mystack.top();
       cout<<p->data<<" ";
       mystack.pop();
       if(p->rchild!=NULL)
        mystack.push(p->rchild);
       if(p->lchild!=NULL)
        mystack.push(p->lchild);
   }
}

void midOrderTraverse(Tree T)
{
   stack<Tree>mystack;
   while(!mystack.empty())
   {
       mystack.pop();
   }
   mystack.push(T);
   TreeNode *p;
   while(!mystack.empty())
   {
       while(mystack.top()!=NULL)
       {
           p = mystack.top();
           mystack.push(p->lchild);
       }
       mystack.pop();
       if(!mystack.empty())
       {
           p = mystack.top();
           cout<<p->data<<" ";
           mystack.pop();
           mystack.push(p->rchild);
       }
   }
}

void postOrderTraverse(Tree T)
{
    stack<Tree>mystack;
    while(!mystack.empty())
    {
        mystack.pop();
    }
    mystack.push(T);
    TreeNode *last = T;
    TreeNode *p;
    while(!mystack.empty())
    {
        p = mystack.top();
        if((p->lchild == NULL && p->rchild == NULL) || last == p->rchild || (p->rchild == NULL && last == p->lchild))
        {
            cout << p->data<<" ";
            last = p;
            mystack.pop();
        }
        else
        {
            if(p->rchild!=NULL)
            {
                mystack.push(p->rchild);
            }
            if(p->lchild!=NULL)
            {
                mystack.push(p->lchild);
            }
        }
    }
}

int main()
{
    //A B C # # D E # G # # F # # #
    Tree T = NULL;
    createTree(&T);
    preOrderTraverse(T);
    cout<<endl;
    midOrderTraverse(T);
    cout<<endl;
    postOrderTraverse(T);
    return 0;
}
