struct pos
{
    int first, second;
};
struct node
{
    struct pos data;   //数据元素
    struct node *next; //指向下一个数据元素的指针
};
typedef struct node *Stack;

//初始化一个空栈
Stack createNullStack(void)
{
    Stack head = new struct node;
    head->next = NULL;
    return head;
}
//入栈函数，参数：入栈数据元素，栈头指针
void push(struct pos x, Stack s)
{
    Stack temp = new struct node;
    temp->data = x;
    temp->next = s->next;
    s->next = temp;
}

//判定栈是否为空，若栈为空，则返回1，否则返回0
int isEmpty(Stack s)
{
    if (s->next == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct pos pop(Stack s)
{
    if (!isEmpty(s))
    {
        struct pos x = s->next->data;
        Stack p = s->next;
        s->next = p->next;
        delete p;
        return x;
    }
    else
    {
        struct pos p1;
        p1.first = 0;
        p1.second = 0;
        return p1;
    }
}
struct pos top(Stack s)
{
    return s->next->data;
}

int getStackLength(Stack s)
{
    int count = 0;
    Stack p = s;
    while (p->next != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}


