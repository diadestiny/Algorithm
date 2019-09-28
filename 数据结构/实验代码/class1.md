```cpp
#include<iostream>
using namespace std;
struct tagNode
{   float coef; //系数
	int exp;   //指数
	struct  tagNode *pNext;
};

typedef struct tagNode Node;
typedef struct tagNode* pNode;
pNode create(){
	int n,e;
	float c;
	pNode L = new Node;
	pNode p = L;
	scanf("%d",&n);
	while (n--){
		scanf("%f%d",&c,&e);
			pNode tmp = new struct tagNode;
			tmp->coef = c;
			tmp->exp = e;
            p->pNext = tmp;
			p=tmp;
	}
		p->pNext = NULL;
		return L;
}
void display(pNode L){
	if (!L->pNext){
		printf("0\n");
		return ;
	}
	pNode p = L->pNext;
	while (p){
		printf("%.0fx^%d",abs(p->coef),p->exp);
		if(p->pNext&&p->pNext->coef>0){
			cout << "+";
		}else if(p->pNext&&p->pNext->coef<0){
			cout << "-";
		}
		p = p->pNext;
		
	}
	cout << endl;
}
pNode add_poly(pNode pa,pNode pb){
	pNode L = new Node;
	pNode p=pa->pNext;
	pNode q=pb->pNext;
	pNode pre = L;
	while (p&&q)
	{
		pNode temp = new Node;
		if(p->exp>q->exp){
			temp->coef = q->coef;
			temp->exp = q->exp;
			pre->pNext = temp;
			pre = temp;
			q = q->pNext;
		}else if(p->exp<q->exp){
			temp->coef = p->coef;
			temp->exp = p->exp;
			pre->pNext = temp;
			pre = temp;
			p = p->pNext;
		}else{
			if(p->coef+q->coef!=0){
				temp->coef = p->coef + q->coef;
				temp->exp = p->exp;
				pre->pNext = temp;
				pre = temp;
			}
			p = p->pNext;
			q = q->pNext;
		}
	}
	while(p){
			pNode temp = new Node;
			temp->coef = p->coef;
			temp->exp = p->exp;
			pre->pNext = temp;
			pre = pre->pNext;
			p = p->pNext;
	}
	while(q){
			pNode temp = new Node;
			temp->coef = q->coef;
			temp->exp = q->exp;
			pre->pNext = temp;
			pre = temp;
			q = q->pNext;
	}
	pre->pNext = NULL;
	return L;
}
pNode sub_poly(pNode pa, pNode pb)
{
	pNode p=pa->pNext;//链表1
	pNode q=pb->pNext;//链表2
	pNode L = new Node;
	pNode pre = L;
	while(p&&q){
		pNode temp = new Node;
		if(p->exp>q->exp){
			temp->coef = -q->coef;
			temp->exp = q->exp;
			pre->pNext = temp;
			pre = temp;
			q = q->pNext;
		}else if(p->exp<q->exp){
			temp->coef = p->coef;
			temp->exp = p->exp;
			pre->pNext = temp;
			pre = temp;
			p = p->pNext;
		}else{
			if(p->coef-q->coef!=0){
				temp->coef = p->coef - q->coef;
				temp->exp = p->exp;
				pre->pNext = temp;
				pre = pre->pNext;
			}
			p = p->pNext;
			q = q->pNext;
		}
	}
	while(p){
			pNode temp = new Node;
			temp->coef = p->coef;
			temp->exp = p->exp;
			pre->pNext = temp;
			pre = temp;
			p = p->pNext;
	}
	while(q){
			pNode temp = new Node;
			temp->coef = -q->coef;
			temp->exp = q->exp;
			pre->pNext = temp;
			pre = temp;
			q = q->pNext;
	}
	pre->pNext = NULL;
	return L;
}
 
int main()
{
	printf("请输入一元多项式L1：\n");
	pNode La = create();
	printf("请输入一元多项式L2：\n");
	pNode Lb = create();
	printf("一元多项式L1：\n");
	display(La);
	printf("一元多项式L2：\n");
	display(Lb);
	printf("L1和L2相加的结果：\n");
	display(add_poly(La, Lb));
	printf("L1与L2相减的结果：\n");
	display(sub_poly(La,Lb));
	return 0;
} 
```
