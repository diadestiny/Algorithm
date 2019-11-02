#include <bits/stdc++.h>
using namespace std;
int num1 = 0;
int num2 = 0;
int num3 = 0;
struct BiTNode
{
    char data;
    struct BiTNode *lChild, *rChild; //���Һ���
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
        T->lChild=creatBitTree(); //����������
        T->rChild=creatBitTree(); //����������
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
    printf("����������������������д���������('#'��ʾ����):\n");
    Tree tree = creatBitTree();
    cout << "����ݹ�:";
    preOrder(tree);
    cout << endl;
    cout << "����ݹ�:";
    inOrder(tree);
    cout << endl;
    cout << "����ݹ�:";
    postOrder(tree);
    cout << endl;
    cout << "��ȱ���:";
    LevelOrder(tree);
    cout << endl;
    cout << "�ǵݹ�����ݹ�:";
    nPreOrder(tree);
    cout << endl;
    cout << "�ǵݹ�����ݹ�:";
    nInOrder(tree);
    cout << endl;
    cout << "�ǵݹ����ݹ�:";
    nPostOrder(tree);
    cout << endl;
    //���ٶ�����
    destoryTree(tree);
    cout << "������" << num1 << endl;
    cout << "��ĸ��" << num2 << endl;
    cout << "����ĸ��������" << num3 << endl;
    return 0;
}