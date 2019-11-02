#include <bits/stdc++.h>
using namespace std;
int num1 = 0;
int num2 = 0;
int num3 = 0;
struct BiTNode
{
    char data;
    struct BiTNode *lChild, *rChild; //左右孩子
};
typedef BiTNode *Tree;
Tree creatBitTree()
{
    Tree T;
    char ch;
    cin >> ch;
    if (ch == '#'){
       T = NULL;
    }
    else{
        T = new BiTNode;
        T->data = ch;
        T->lChild=creatBitTree(); //构造左子树
        T->rChild=creatBitTree(); //构造右子树
    }
    return T;
}
void check(int letter){
    if((letter>='a'&&letter<='z')||(letter>='A'&&letter<='Z')){
            num2++;
        }else{
            num1++;
        }
}
void preOrder(Tree T){
    if (T)
    {  
        cout << T->data;
        check(T->data);
        preOrder(T->lChild); 
        preOrder(T->rChild);
    }
    else{
        num3++;
        cout << "";
    }
        
}
void inOrder(Tree T){
    if (T)
    {  
        inOrder(T->lChild); 
        cout << T->data;
        inOrder(T->rChild);
    }
    else
        cout << "";
}
void postOrder(Tree T){
    if (T)
    {  
        postOrder(T->lChild); 
        postOrder(T->rChild);
        cout << T->data;
    }
    else
        cout << "";
}
void LevelOrder(Tree T){
    if(T==NULL) return;
    queue<Tree> q;
    q.push(T);
    while(!q.empty()){
        Tree temp = q.front();
        q.pop();
        cout << temp->data;
        if(temp->lChild!=NULL)
            q.push(temp->lChild);
        if(temp->rChild!=NULL)
            q.push(temp->rChild);
    }
}
void nPreOrder(Tree T){
    stack<Tree> s;
    Tree temp = T;
    while(temp!=NULL||!s.empty()){
        while(temp!=NULL){
            cout << temp->data << "";
            s.push(temp);
            temp = temp->lChild;
        }
        if(!s.empty()){
            temp = s.top();
            s.pop();
            temp = temp->rChild;
        }
    }
}
void nInOrder(Tree T){
    stack<Tree> s;
    Tree temp = T;
    while(temp!=NULL||!s.empty()){
        while(temp!=NULL){
            s.push(temp);
            temp = temp->lChild;
        }
        if(!s.empty()){
            temp = s.top();
            cout << temp->data << "";
            s.pop();
            temp = temp->rChild;
        }
    }
}
void nPostOrder(Tree T){
    stack<Tree> s;
    Tree temp=T;
    while(temp!=NULL||!s.empty()){
        while (temp!=NULL)
        {
            s.push(temp);
            temp = temp->lChild ? temp->lChild : temp->rChild;
        }
        temp = s.top();
        s.pop();
        cout << temp->data << "";
        if(!s.empty()&& temp==s.top()->lChild) 
        {temp = s.top()->rChild;}
        else temp = NULL;
    }
}
void destoryTree(Tree &T){
    if(T==NULL) return;
    if(T->lChild!=NULL)destoryTree(T->lChild);
    if(T->rChild!=NULL)destoryTree(T->rChild);
    free(T);
    T = NULL;
}
int main()
{
    printf("根据输入二叉树的先序序列创建二叉树('#'表示结束):\n");
    Tree tree = creatBitTree();
    cout << "先序递归:";
    preOrder(tree);
    cout << endl;
    cout << "中序递归:";
    inOrder(tree);
    cout << endl;
    cout << "后序递归:";
    postOrder(tree);
    cout << endl;
    cout << "广度遍历:";
    LevelOrder(tree);
    cout << endl;
    cout << "非递归先序递归:";
    nPreOrder(tree);
    cout << endl;
    cout << "非递归中序递归:";
    nInOrder(tree);
    cout << endl;
    cout << "非递归后序递归:";
    nPostOrder(tree);
    cout << endl;
    //销毁二叉树
    destoryTree(tree);
    cout << "数字有" << num1 << endl;
    cout << "字母有" << num2 << endl;
    cout << "非字母和数字有" << num3 << endl;
    return 0;
}