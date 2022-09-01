#include <stdio.h>
#include <stdlib.h>
#define capacity 100

typedef struct
{
  int que[capacity];
  int front, rear;
} Queue;

void init_queue(Queue *q) //ť �ʱ�ȭ
{
  q->front = q->rear = 0;
}

int is_full(Queue *q)
{
  return ((q->rear + 1) % capacity == q->front);
}

int is_empty(Queue *q)
{
  return (q->front == q->rear);
}

void push(Queue *q, int value)
{
  if (is_full(q)) // que�� �����ִٸ� return
    return;

  q->rear = (q->rear + 1) % capacity;
  q->que[q->rear] = value;
}

int pop(Queue *q)
{
  if (is_empty(q)) // que�� ����ִٸ� -1 ����
    return -1;

  q->front = (q->front + 1) % capacity;
  return q->que[q->front];
}

int size(Queue *q) // que�� ũ�⸦ ��ȯ
{
  if (q->front < q->rear)
    return q->rear - q->front;
  else
    return capacity - q->front + q->rear;
}
