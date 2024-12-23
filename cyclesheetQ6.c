#include <stdio.h>
#define size 100
struct queue
{
    int que[size];
    int front, rear;
} q;
void init()
{
    q.rear = q.front = -1;
}
int full()
{
    if (q.rear >= size - 1)
    {
        printf("queue overflow:\n");
        return 1;
    }
    return 0;
}
int empty()
{
    if (q.front == -1 || q.front > q.rear)
    {
        printf("queue underflow\n");
        return 1;
    }
    return 0;
}
int insert(int item)
{
    if (q.front == size - 1)
    {
        printf("queue overflow\n");
        return 0;
    }
    if (q.front == -1)
    {
        q.front++;
    }
    q.que[++q.rear] = item;
    return q.rear; // hii ndo nini?
}
int delete()
{
    if (empty())
    {
        printf("queue underflow\n");
        return 0;
    }
    int item;
    item = q.que[q.front];
    q.front++;
}
void display()
{
    if (q.front == -1 || q.front > q.rear)
    {
        printf("queue is empty\n");
        return;
    }
    for (int i = q.front; i <= q.rear; i++)
    {
        printf("%d \n", q.que[i]);
    }
}
int main()
{
    init();
    insert(2);
    insert(4);
    insert(6);
    insert(8);
    insert(10);
    printf("the queue is 1:\n");
    display();
    delete ();
    delete ();
    delete ();
    printf("the queue is 2:\n");
    display();
    delete ();
    printf("the queue is 3 :\n");
    display();
    delete ();
    printf("the queue is 4:\n");
    display();
}