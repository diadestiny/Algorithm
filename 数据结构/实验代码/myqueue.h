struct Node
{
    int r, c;
    Node(int r, int c) : r(r), c(c) {}
    Node() {}
};
struct QNode    //定义队列结点的数据结构
{
	QNode *next; //指针域,指向下一个结点
	struct Node data;    //数据域，存储队列信息
};
 
struct LinkQueue    //定义队列的数据结构
{
	QNode *front;      //队首指针,指向QNode类型的指针
	QNode *rear;       //队尾指针
};
 
void InitQueue(LinkQueue &Q)     //构造一个空的队列
{
	QNode *q;
	q = new QNode;    //申请一个结点的空间
	q->next = NULL;   //当作头结点
	//队首与队尾指针都指向这个结点，指针域为NULL
	Q.front = q;
	Q.rear = q;
}
 
int IsEmpty(LinkQueue &Q)    //判断队列是否为空 空返回1,否则返回0
{
	if (Q.rear == Q.front)
		return 1;
	else
		return 0;
}
 
void EnQueue(LinkQueue &Q, Node e)     //从队列尾部插入元素
{
	QNode *p;    //新创建一个结点
	p = new QNode;
	p->next = NULL;
	p->data = e;  //输入数据信息
	//将新结点插入队列尾部
	Q.rear->next = p;
	Q.rear = p;       //设置新的尾结点
}
 
void DeQueue(LinkQueue &Q)   //从队列首部删除一个结点
{
	QNode *p;
	p = Q.front->next;
	Q.front->next = p->next;       //将下一个结点当作头结点后面链接的第一个结点
	if (Q.rear == p)    //如果要删除的元素即为尾结点，则将头指针赋予尾指针，一同指向头结点，表示队列为空
		Q.rear = Q.front;
	delete p;
}
 
void DestoryQueue(LinkQueue &Q)       //销毁一个队列
{
	while (Q.front)
	{
		Q.rear = Q.front;    //从头节点开始，一个一个删除队列结点，释放空间
		delete Q.front;
		Q.front = Q.rear;
	}
}
int getQueueLength(LinkQueue Q){
	QNode *pcur;
	int count =0;
    pcur =Q.front;
  	while(pcur->next!=NULL)
  	{
		pcur=pcur->next;
   		count++;
  	}
  	return count;
}
struct Node front(LinkQueue Q)
{
    return Q.front->next->data;
}