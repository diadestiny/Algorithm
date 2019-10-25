#define MAXSIZE 100 //队列的最大长度
typedef int ElemType;
typedef struct SeqQueue
{
    ElemType data[MAXSIZE]; //队列的存储空间
    int front, rear;        //队列的队头指针和队尾指针
} SqQueue;
//初始化队列
void Init_SqQueue(SqQueue *Q)
{
    Q->front = Q->rear = 0;
}
//判断队列是否为空
int Empty_SqQueue(SqQueue *Q)
{
    return Q->rear == Q->front; //为真，返回1 则表示队列为空
}
//数据 e 进队列
void In_SqQueue(SqQueue *Q, int e)
{
    if ((Q->rear + 1) % MAXSIZE == Q->front)
    {
        return;
    }
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXSIZE;
}
//数据出队列，通过将出队列数据赋值给 e
void Out_SqQueue(SqQueue *Q, int *e)
{
    //出队之前，先判断队列是否为空
    if (Q->rear == Q->front)
    {
        return;
    }
    *e = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;
}
ElemType frontQueue_seq(SqQueue* Q)  /* 对非空队列,求队列头部元素 */
{
    return (Q->data[Q->front]);
}
